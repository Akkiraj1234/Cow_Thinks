#include "utils.cpp"


void formatted_text(const std::string& text, const int& char_size) {
    // Clear the terminal screen and move the cursor to the top
    bool vitual_terminal = virtual_terminal_activate();
    scroll_up();

    std::string text1 = "";
    auto [width, height] = getTerminalSize();
    int text_size = (width - char_size);
    text_size = text_size > 50 ? text_size - 10 : text_size;

    std::string dash(text_size - 4, '-');

    // Print the formatted text box with text
    std::cout << " /" << dash << "\\ " << std::endl;
    std::cout << "/" << std::string(text_size - 2, ' ') << "\\" << std::endl;
    std::cout << "| " << text << std::string(text_size - 4 - text.length(), ' ') << " |" << std::endl;
    std::cout << "\\" << std::string(text_size - 2, ' ') << "/" << std::endl;
    std::cout << " \\" << dash << "/ " << std::endl;

    // ----------------------------------------------------------------------------
    // Debugging output for terminal size
    std::cout << "width: " << width << ", height: " << height << std::endl;
    std::cout << text << std::endl;
}


int main(){
    std::string data;
    data = "hello this is formated text";
    formatted_text(data, 22);

    return 0;
}