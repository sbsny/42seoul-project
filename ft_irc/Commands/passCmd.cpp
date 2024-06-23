#include "Commands.hpp"

void	Commands::passCmd()
{
	if (!this->_user->passwordIsSet())
	{
		if (this->_line_cmd.size() < 2)
			this->_msg->ERR_NEEDMOREPARAMS(this->_fd_user);
		else if (this->_line_cmd[1] == this->_s->getPassword())
		{
			this->_user->setPassword();
			std::cout << " >> " << "Correct password!"  << std::endl;
		}
		else
		{
			this->_msg->ERR_PASSWDMISMATCH(this->_fd_user);
			this->_user->increment_pass_try();
			std::cout << " >> " << "Incorrect password!" << std::endl;
			if (this->_user->get_pass_try() == 3)
			{
				this->_s->setFdUsersDc(this->_fd_user);
				std::cout << " >> " <<  "Client: " << this->_fd_user << " has been disconnected." << std::endl;
			}
		}
	}
	else if (this->_line_cmd[0] == "PASS" && this->_user->passwordIsSet())
		this->_msg->ERR_ALREADYREGISTRED(this->_fd_user);
}
