namespace lscb {
	namespace utility {

	}

	namespace command {

		class Command {
			Command() {}
			
			/// <summary>
			/// The help text returned when the help command is invoked without arguments. Should be very
			/// short.
			/// </summary>
			virtual std::string help_text() = 0;

			/// <summary>
			/// The help text returned when help <this command> is invoked. It should be more detailed than
			/// the help_text description.
			/// </summary>
			virtual std::string help_description() = 0;
			 
		};

		/// <summary>
		/// A command which completes some sort of function, can have arguments, etc
		/// </summary>
		class Functional_Command : public Command {
			std::string help_text() override {
				return "Call me and I'll do something cool!";
			}
		};

		// A purely static command. Will respond with some predetermined text message or embedded message.
		class Static_Command : public Command {
			std::string help_text() override {
				return "Call me and I'll say something cool!";
			}
		};
	}
}