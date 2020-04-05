//
// Created by Manish  on 3/30/20.
//
#ifndef SHELL_PHASE2_MYSHELL_H
#define SHELL_PHASE2_MYSHELL_H
#include <map>
#include <vector>
#include <string>
#include <map>

class MyShell {
private:
    typedef void (MyShell::*Command_Function_Pointer)();
    static std::map<std::string, MyShell::Command_Function_Pointer> COMMAND_MAP;
    bool error; // if any error occurs in previous steps, used in the parent process, if any error occurs in a child process, the child one just exits
    bool exitting; // if the shell will exit in the next step
    std::string input; // initial one-line user input
    std::vector<std::string> piped_commands; // piped commands in user input
    std::vector<std::string> commands; // one command and its arguments
    int * pipefd; // an array of pipe fd used to run piped commands
    std::size_t curr_command_index;
    std::size_t num_child_processes; // number of child processes forked
    std::map<std::string, std::string> vars; // internal map of Shell variables and values
    void setVar(std::string key, std::string value);
    void evaluateVars();
    void parsePipedInput();
    void parseCommand();
    bool searchCommand();
    void runExitCommands();
    void runCdCommand();
    void runSetCommand();
    void runExportCommand();
    void configCommandRedirect();
    void configCommandPipe(bool redirect_input, bool redirect_output);
    void runCommand();
    void createPipes();
    void closePipes();
    void waitForChildProcesses();
    void runPipedCommands();
    void refresh();
public:
    MyShell();
    void execute();
    bool isExitting();
};

#endif


