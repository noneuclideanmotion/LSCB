#include <string>
#include <fstream>
#include <sstream>

#include "sleepy_discord/sleepy_discord.h"
#include "sleepy_discord/rapidjson/document.h"


namespace lscb {
	/// <summary>
	/// General utility functions and classes.
	/// </summary>
	namespace utility {
		/// <summary>
		/// Will retreve a token from a file (which should contain only the token). 
		/// The token is kept seperate from the other configuration options, in its own file
		/// for safety reasons. 
		/// </summary>
		/// <param name="relative_path"></param>
		/// <returns>A string containing the token contained the file</returns>
		std::string read_token_from_file(const std::string& relative_path) {
			std::ifstream token_file(relative_path, std::ios::in | std::ios::binary);
			std::stringstream token_stream;
			token_stream << token_file.rdbuf();
			return token_stream.str();
		}


		namespace get_image_url {
			/// <summary>
			/// Get's the URL of a user's avatar
			/// </summary>
			/// <param name="user">The user whose avatar URL you want</param>
			/// <param name="size">
			/// The size of the image. Sizes must be in powers of two so this must be in the range [4,11].
			/// Where the resolution of the image returned is 2^size. Minumum resolution 16x16(size=4), maximum resolution is the original
			/// resolution of the image when it was uploaoded
			/// The default value is 128x128(size=7)
			/// </param>
			/// <returns>The url of the user's avatar.</returns>
			std::string avatar(const SleepyDiscord::User& user, uint16_t size = 0) {
				if (size == 0)
					return  "https://cdn.discordapp.com/avatars/" + user.ID.string() + "/" + user.avatar + ".png";
				else if (size < 4)
					size = 4;
				return  "https://cdn.discordapp.com/avatars/" + user.ID.string() + "/" + user.avatar + ".png?size=" + std::to_string(1 << size);
			}

			//NOT IMPLEMENTED
			std::string _avatar(const std::string& ID) {
				// TODO: need to make a helper function to request discord user data from their ID in order
				// to make this function work
				return  "Not yet implemented";
			}

			/// <summary>
			/// Get's an emoji URL (Image file) from it's ID
			/// </summary>
			/// <param name="ID">ID of the emoji. Can be found by typing \:emoji_name: into discord</param>
			/// <returns>The URL of the emoji's image file, as stored on the discord CDN server</returns>
			std::string emoji(const std::string& ID) {
				return  "https://cdn.discordapp.com/emojis/" + ID + ".png";
			}

			/// <summary>
			/// Get the icon URL of a guild (image file) logo. My personal preference is to call them servers however
			/// I am using the naming convention of the discord API here.
			/// </summary>
			/// <param name="guild"></param>
			/// <returns>The URL (image file) of the stated guild (server)'s logo. </returns>
			std::string guild_icon(const SleepyDiscord::Server& guild) {
				return  "https://cdn.discordapp.com/icons/" + guild.ID.string() + "/" + guild.icon + ".png";
			}

			/// <summary>
			/// Get the splash URL of a guild (image file) logo. My personal preference is to call them servers however
			/// I am using the naming convention of the discord API here. Unfortunately I don't actually know what the 
			/// splash is.
			/// </summary>
			/// <param name="guild"></param>
			/// <returns>The URL (image file) of the stated guild (server)'s splash. </returns>
			std::string guild_splash(const SleepyDiscord::Server& guild) {
				return  "https://cdn.discordapp.com/splashes/" + guild.ID.string() + "/" + guild.splash + ".png";
			}

			//NYI. I must extend the library manually to retrieve this information from the discord API.
			std::string _guild_banner(const SleepyDiscord::Server& guild) {
				return  "https://cdn.discordapp.com/banners/" + guild.ID.string() + "/" + "---" + ".png";
			}
		}

		/// <summary>
		/// Helper functions for making easier to use SleepyDiscord embed objects without needing.
		/// </summary>
		namespace make_embed {
			/// <summary>
			/// Makes an EmbedImage object from some parameters.
			/// </summary>
			/// <param name="url">Url pointing to the image</param>
			/// <param name="size">A pair taking the size of the image to display (not the resolution of the image).</param>
			/// <param name="proxy_url"></param>
			/// <returns>A SleepyDiscord::EmbedImage object</returns>
			SleepyDiscord::EmbedImage image(const std::string& url, const std::pair<uint16_t, uint16_t>& size, const std::string& proxy_url = "") {
				//return SleepyDiscord::EmbedImage("{\"url\" :  \"" + url + "\" ,\"proxy_url\" : \"" + proxy_url + "\" ,\"width\" : " + std::to_string(size.first) + ",\"height\" : " + std::to_string(size.second) + ",}");
				rapidjson::Document d;
				std::string json = "{ \
						 \"url\" : \" " + url + " \", \
						 \"proxy_url\" : \" " + proxy_url + " \", \
						 \"width\" : " + std::to_string(size.first) + ", \
						 \"height\" : " + std::to_string(size.second) + " \
					}";
				return SleepyDiscord::EmbedImage(d.Parse(json.c_str()));
			}

			/// <summary>
			/// Creates an EmbedAuthor object easily. Can be used for embeds. This function takes the properties of the authour
			/// for custom authours. The authour is displayed at the top of the embed.
			/// </summary>
			/// <param name="author_name">Name of the authour</param>
			/// <param name="author_url">The url which the authour's name links to</param>
			/// <param name="icon_url">The Icon (profile picture) of the authour</param>
			/// <param name="proxy_icon_url">Backup url for the icon of the authour</param>
			/// <returns>An easy to use EmbedAuthor object</returns>
			SleepyDiscord::EmbedAuthor author(const std::string& author_name, const std::string& author_url, 
				const std::string& icon_url = "https://cdn.discordapp.com/avatars/user_discriminator.png", const std::string& proxy_icon_url = "") {
				rapidjson::Document d;
				std::string json = "{ \
						\"name\" : \" " + author_name + " \", \
						\"url\" : \" " + author_url + " \", \
						\"icon_url\" : \" " + icon_url + " \", \
						\"proxy_icon_url\" : \" " + proxy_icon_url + " \" \
					}";
				return SleepyDiscord::EmbedAuthor(d.Parse(json.c_str()));
			}
			
			/// <summary>
			/// Creates an embedAuthor object from a real discord user
			/// </summary>
			/// <param name="user"></param>
			/// <returns>An easy to use EmbedAuthor object</returns>
			SleepyDiscord::EmbedAuthor author(const SleepyDiscord::User& user, const bool& show_discriminator = false) {
				rapidjson::Document d;
				std::string json = "{ \
						\"name\" : \" " + user.username + (show_discriminator ? "#" + user.discriminator : "") + " \", \
						\"url\" : \" " + "" + " \", \
						\"icon_url\" : \" " + utility::get_image_url::avatar(user) + " \", \
						\"proxy_icon_url\" : \" " + "" + " \" \
					}";
				return SleepyDiscord::EmbedAuthor(d.Parse(json.c_str()));
			}
		}	
	}
}