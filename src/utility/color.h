#include <cstdint>

namespace lscb {
	namespace utility {
		/// <summary>
		/// The colour namespace contains the hex codes of all the basic CSS colours as constants.
		/// It also contains the discord colour scheme in ::discord. And X11 Extended CSS colours in
		/// ::extended.
		/// 
		/// It also contains the helper class color which can be called with a hex string or rgb value to
		/// convert that into a readable form to send via json to the discord API.
		/// </summary>
		namespace color {
			const int32_t black = 0x000000;
			const int32_t silver = 0xc0c0c0;
			const int32_t gray = 0x808080;
			const int32_t white = 0xffffff;
			const int32_t maroon = 0x800000;
			const int32_t red = 0xff0000;
			const int32_t purple = 0x800080;
			const int32_t fuchsia = 0xff00ff;
			const int32_t green = 0x008000;
			const int32_t lime = 0x00ff00;
			const int32_t olive = 0x808000;
			const int32_t yellow = 0xffff00;
			const int32_t navy = 0x000080;
			const int32_t blue = 0x0000ff;
			const int32_t teal = 0x008080;
			const int32_t aqua = 0x00ffff;

			/// <summary>
			/// CSS X11 Standard extended colours.
			/// </summary>
			namespace extended {
				const int32_t aliceblue = 0xf0f8ff;
				const int32_t antiquewhite = 0xfaebd7;
				const int32_t aqua = 0x00ffff;
				const int32_t aquamarine = 0x7fffd4;
				const int32_t azure = 0xf0ffff;
				const int32_t beige = 0xf5f5dc;
				const int32_t bisque = 0xffe4c4;
				const int32_t black = 0x000000;
				const int32_t blanchedalmond = 0xffebcd;
				const int32_t blue = 0x0000ff;
				const int32_t blueviolet = 0x8a2be2;
				const int32_t brown = 0xa52a2a;
				const int32_t burlywood = 0xdeb887;
				const int32_t cadetblue = 0x5f9ea0;
				const int32_t chartreuse = 0x7fff00;
				const int32_t chocolate = 0xd2691e;
				const int32_t coral = 0xff7f50;
				const int32_t cornflowerblue = 0x6495ed;
				const int32_t cornsilk = 0xfff8dc;
				const int32_t crimson = 0xdc143c;
				const int32_t cyan = 0x00ffff;
				const int32_t darkblue = 0x00008b;
				const int32_t darkcyan = 0x008b8b;
				const int32_t darkgoldenrod = 0xb8860b;
				const int32_t darkgray = 0xa9a9a9;
				const int32_t darkgreen = 0x006400;
				const int32_t darkgrey = 0xa9a9a9;
				const int32_t darkkhaki = 0xbdb76b;
				const int32_t darkmagenta = 0x8b008b;
				const int32_t darkolivegreen = 0x556b2f;
				const int32_t darkorange = 0xff8c00;
				const int32_t darkorchid = 0x9932cc;
				const int32_t darkred = 0x8b0000;
				const int32_t darksalmon = 0xe9967a;
				const int32_t darkseagreen = 0x8fbc8f;
				const int32_t darkslateblue = 0x483d8b;
				const int32_t darkslategray = 0x2f4f4f;
				const int32_t darkslategrey = 0x2f4f4f;
				const int32_t darkturquoise = 0x00ced1;
				const int32_t darkviolet = 0x9400d3;
				const int32_t deeppink = 0xff1493;
				const int32_t deepskyblue = 0x00bfff;
				const int32_t dimgray = 0x696969;
				const int32_t dimgrey = 0x696969;
				const int32_t dodgerblue = 0x1e90ff;
				const int32_t firebrick = 0xb22222;
				const int32_t floralwhite = 0xfffaf0;
				const int32_t forestgreen = 0x228b22;
				const int32_t fuchsia = 0xff00ff;
				const int32_t gainsboro = 0xdcdcdc;
				const int32_t ghostwhite = 0xf8f8ff;
				const int32_t gold = 0xffd700;
				const int32_t goldenrod = 0xdaa520;
				const int32_t gray = 0x808080;
				const int32_t green = 0x008000;
				const int32_t greenyellow = 0xadff2f;
				const int32_t grey = 0x808080;
				const int32_t honeydew = 0xf0fff0;
				const int32_t hotpink = 0xff69b4;
				const int32_t indianred = 0xcd5c5c;
				const int32_t indigo = 0x4b0082;
				const int32_t ivory = 0xfffff0;
				const int32_t khaki = 0xf0e68c;
				const int32_t lavender = 0xe6e6fa;
				const int32_t lavenderblush = 0xfff0f5;
				const int32_t lawngreen = 0x7cfc00;
				const int32_t lemonchiffon = 0xfffacd;
				const int32_t lightblue = 0xadd8e6;
				const int32_t lightcoral = 0xf08080;
				const int32_t lightcyan = 0xe0ffff;
				const int32_t lightgoldenrodyellow = 0xfafad2;
				const int32_t lightgray = 0xd3d3d3;
				const int32_t lightgreen = 0x90ee90;
				const int32_t lightgrey = 0xd3d3d3;
				const int32_t lightpink = 0xffb6c1;
				const int32_t lightsalmon = 0xffa07a;
				const int32_t lightseagreen = 0x20b2aa;
				const int32_t lightskyblue = 0x87cefa;
				const int32_t lightslategray = 0x778899;
				const int32_t lightslategrey = 0x778899;
				const int32_t lightsteelblue = 0xb0c4de;
				const int32_t lightyellow = 0xffffe0;
				const int32_t lime = 0x00ff00;
				const int32_t limegreen = 0x32cd32;
				const int32_t linen = 0xfaf0e6;
				const int32_t magenta = 0xff00ff;
				const int32_t maroon = 0x800000;
				const int32_t mediumaquamarine = 0x66cdaa;
				const int32_t mediumblue = 0x0000cd;
				const int32_t mediumorchid = 0xba55d3;
				const int32_t mediumpurple = 0x9370db;
				const int32_t mediumseagreen = 0x3cb371;
				const int32_t mediumslateblue = 0x7b68ee;
				const int32_t mediumspringgreen = 0x00fa9a;
				const int32_t mediumturquoise = 0x48d1cc;
				const int32_t mediumvioletred = 0xc71585;
				const int32_t midnightblue = 0x191970;
				const int32_t mintcream = 0xf5fffa;
				const int32_t mistyrose = 0xffe4e1;
				const int32_t moccasin = 0xffe4b5;
				const int32_t navajowhite = 0xffdead;
				const int32_t navy = 0x000080;
				const int32_t oldlace = 0xfdf5e6;
				const int32_t olive = 0x808000;
				const int32_t olivedrab = 0x6b8e23;
				const int32_t orange = 0xffa500;
				const int32_t orangered = 0xff4500;
				const int32_t orchid = 0xda70d6;
				const int32_t palegoldenrod = 0xeee8aa;
				const int32_t palegreen = 0x98fb98;
				const int32_t paleturquoise = 0xafeeee;
				const int32_t palevioletred = 0xdb7093;
				const int32_t papayawhip = 0xffefd5;
				const int32_t peachpuff = 0xffdab9;
				const int32_t peru = 0xcd853f;
				const int32_t pink = 0xffc0cb;
				const int32_t plum = 0xdda0dd;
				const int32_t powderblue = 0xb0e0e6;
				const int32_t purple = 0x800080;
				const int32_t red = 0xff0000;
				const int32_t rosybrown = 0xbc8f8f;
				const int32_t royalblue = 0x4169e1;
				const int32_t saddlebrown = 0x8b4513;
				const int32_t salmon = 0xfa8072;
				const int32_t sandybrown = 0xf4a460;
				const int32_t seagreen = 0x2e8b57;
				const int32_t seashell = 0xfff5ee;
				const int32_t sienna = 0xa0522d;
				const int32_t silver = 0xc0c0c0;
				const int32_t skyblue = 0x87ceeb;
				const int32_t slateblue = 0x6a5acd;
				const int32_t slategray = 0x708090;
				const int32_t slategrey = 0x708090;
				const int32_t snow = 0xfffafa;
				const int32_t springgreen = 0x00ff7f;
				const int32_t steelblue = 0x4682b4;
				const int32_t tan = 0xd2b48c;
				const int32_t teal = 0x008080;
				const int32_t thistle = 0xd8bfd8;
				const int32_t tomato = 0xff6347;
				const int32_t turquoise = 0x40e0d0;
				const int32_t violet = 0xee82ee;
				const int32_t wheat = 0xf5deb3;
				const int32_t white = 0xffffff;
				const int32_t whitesmoke = 0xf5f5f5;
				const int32_t yellow = 0xffff00;
				const int32_t yellowgreen = 0x9acd32;
			}

			/// <summary>
			/// Chat is the background colour for the discord default theme
			/// Embed is dually the colour of an embedded message and the colour of the sidebar
			/// Blue is the blue colour found in discords logo
			/// </summary>
			namespace discord {

				const int32_t chat = 0x36393e;
				const int32_t embed = 0x23272a;
				const int32_t blue = 0x7289DA;
			}
		}

		/// <summary>
		/// Takes an input of a hex code (without leading # or 0x and returns an integer.
		/// </summary>
		/// <param name="hex">Hex String</param>
		/// <returns>Colour in a discord API format</returns>
		int32_t make_color(const std::string& hex)
		{
			return std::stoi(hex, nullptr, 16);	
		}

		/// <summary>
		/// Takes an input of an RGB tuple and returns an integer.
		/// </summary>
		/// <param name="r">Red value</param>
		/// <param name="g">Green Value</param>
		/// <param name="b">Blue Value</param>
		/// <returns>Colour in a discord API format</returns>
		int32_t make_color(const int r, const int g, const int b)
		{
			int32_t hex =  static_cast<int32_t>((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
			// discord does not allow 0xffffff
			if (hex == 0xffffff) return 0xfffffe;
			return hex;
		}
		
	}
}
