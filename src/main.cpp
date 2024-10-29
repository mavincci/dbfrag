#include <CLI/CLI.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    CLI::App app{"dbfrag"};
    bool flag = false;
    app.add_flag("-f,--flag", flag, "Sample flag");

    CLI11_PARSE(app, argc, argv);
    std::cout << "Flag value: " << flag << std::endl;
    return 0;
}
