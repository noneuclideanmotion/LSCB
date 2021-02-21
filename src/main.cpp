#include "utility/utility.h"
#include "sleepy_discord/sleepy_discord.h"
#include "utility/html_request.h"
#include <algorithm>

#include "utility/color.h"

namespace lscb
{
	enum class command
	{
		repeat,
		hello
	};

	std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
		}
		return str;
	}

	const std::string client_prefix = ">";
}


class lscb_client : public SleepyDiscord::DiscordClient {
public:
	using SleepyDiscord::DiscordClient::DiscordClient;
	void onMessage(SleepyDiscord::Message message) override {
		if (message.startsWith(lscb::client_prefix + "hello")) {
			sendMessage(message.channelID, "Hello " + message.author.username);
		}
		else if (message.startsWith(lscb::client_prefix + "repeat")) {
			sendMessage(message.channelID, message.content.substr(8));
		}
		else if (message.startsWith(lscb::client_prefix + "uwu")) {
			std::stringstream ss(message.content.substr(5));       // Insert the string into a stream
			std::vector<std::string> tokens; // Create vector to hold our words
			std::string buf;
			while (ss >> buf)
				tokens.push_back(buf);
			sendMessage(message.channelID, tokens[0] + " is suwper duwper uwu <3");
		}
		else if (message.startsWith(lscb::client_prefix + "status")) {
			updateStatus(message.content.substr(8));
		}
		else if (message.startsWith(lscb::client_prefix + "request")) {
			try {
				// you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
				http::Request request("http://example.com/");

				// send a get request
				const http::Response response = request.send("GET");
				sendMessage(message.channelID, "```\n" + std::string(response.body.begin(), response.body.end()) + "\n```");
			}
			catch (const std::exception& e) {
				std::cerr << "Request failed, error: " << e.what() << '\n';
			}
		}
		else if (message.startsWith(lscb::client_prefix + "continue")) {
			try {
				// you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
				std::string sequence = message.content.substr(10);
				sequence = lscb::ReplaceAll(sequence, " ", "%20");
				std::cout << "http://oeis.org/search?fmt=text&q=" + sequence << std::endl;
				http::Request request("http://oeis.org/search?fmt=text&q=" + sequence);

				// send a get request
				const http::Response response = request.send("GET");
				sequence = std::string(response.body.begin(), response.body.end());
				std::size_t sequence_first = sequence.find("%S ");
				std::size_t sequence_last = sequence.find("\n", sequence_first);
				sequence = sequence.substr(sequence_first+11, sequence_last-sequence_first-12);
				sendMessage(message.channelID, "```\n My best guess to continue this sequence is:\n" + sequence + "\n```");
			}
			catch (const std::exception& e) {
				std::cerr << "Request failed, error: " << e.what() << '\n';
			}
		}
		else if (message.startsWith(lscb::client_prefix + "embed")) {
			SleepyDiscord::Embed embed;
			embed.color = lscb::utility::make_color(255, 254, 255);
			embed.url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";
			embed.title = "Colour";
			embed.image = lscb::utility::make_embed::image(message.content.substr(7),
				std::make_pair<uint16_t, uint16_t>(200, 300));
			embed.author = lscb::utility::make_embed::author(message.author);
			embed.description = "Colour selected - " + message.content.substr(7, 6);
			sendMessage(message.channelID, "", embed);
		}
		else if (message.startsWith(lscb::client_prefix + "avatar")) {
			SleepyDiscord::Embed embed;
			embed.color = lscb::utility::color::aqua;
			embed.url = lscb::utility::get_image_url::avatar(message.author);
			embed.title = "Your Avatar";
			embed.image = lscb::utility::make_embed::image(lscb::utility::get_image_url::avatar(message.author, 8),
				std::make_pair<uint16_t, uint16_t>(1000, 1000));
			sendMessage(message.channelID, "", embed);
		}

	}
};

int main() {
	lscb_client client(lscb::utility::read_token_from_file("./config/token"), SleepyDiscord::USER_CONTROLED_THREADS);
	client.run();
	std::cout << std::endl << lscb::utility::make_color(255, 255, 255) << std::endl;

}
