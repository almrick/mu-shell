// Standard includes
#include <iostream>
#include <map>
#include <string>
#include <vector>

// C includes
#include <unistd.h>

class MuShell
{
private:
    std::string m_line;
    std::vector<char*> m_tokens;
    std::unordered_map<std::string, std::string> m_defs;
    int m_status;
    
public:
    MuShell()
    {}

    ~MuShell()
    {}

    void Run()
    {
	while (true)
	{
	    std::cout << "mu$ ";
	    std::cin << m_line;

	    Tokenise();
	    Execute();

	    std::cout << "Exited with " << m_status << std::endl; 
	}
    }
    
private:
    void Tokenise()
    {
	for (std::size_t i = 0; i < line.size(); i++)
	{   
	    switch (line[i])
	    {
	    case ' ':
	    case '\n':
	    case '\r':
		break;
	    case '#':
		while (i < line.size())
		    i++;
		break;
	    case '$':
		break;
	    default:
	    {
	        std::string buffer;
		while (i < line.size() && line[i])
		    buffer += line[i];
		tokens.push_back(buffer.data());
	    } break;
	    }
	}
    }

    void Execute()
    {
	// Create a new child process
	auto childPid = fork();
	if (fork < 0)
	{
	    std::exit(1);
	}
	
	// Convert the vector in to a pointer to the data
	// on the heap for execvp.
	auto cmdArgs = m_tokens.data();
	
	// Execute the program
	if (execvp(cmdArgs[0], cmdArgs))
	{
	    std::exit(1);
	}
	
        // Wait for the program to finish
	waitpid(childPid, &m_status, 0);
    }
};

int main()
{
    MuShell mu;
    mu.Run();
}
