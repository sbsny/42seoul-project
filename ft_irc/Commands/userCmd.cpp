#include "Commands.hpp"

void	Commands::userCmd()
{
	std::string realname;

	if(!this->_user->realnameIsSet())
	{
		if (this->_line_cmd.size() < 5 || this->_line_cmd[4][0] != ':')
		{
			this->_msg->ERR_NEEDMOREPARAMS(this->_fd_user);
			return;
		}
		if (this->_line_cmd[4][0] == ':' && this->_line_cmd[4].size() >= 2)
		{
			this->_line_cmd[4] = this->_line_cmd[4].substr(1, this->_line_cmd[4].size() - 1);
			if(this->_line_cmd.size() == 5)
			{
				std::string realname = this->_line_cmd[4];
				this->_user->setRealname(realname);
			}
			else if(this->_line_cmd.size() >= 2 && this->_line_cmd.size() != 5)
			{
				std::string realname = this->_line_cmd[4] + " " + this->_line_cmd[5];
				this->_user->setRealname(realname);
			}
			this->_user->setUser(this->_line_cmd[1]);
			std::cout << " >> " << "Realname: " << this->_user->getRealname() << std::endl;
			std::cout << " >> " << "User: " << this->_user->getUser() << std::endl;
		}
	}
	else if(_line_cmd[0] == "USER" && this->_user->realnameIsSet())
		this->_msg->ERR_ALREADYREGISTRED(this->_fd_user);

}
