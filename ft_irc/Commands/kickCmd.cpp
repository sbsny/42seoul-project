#include "Commands.hpp"

void	Commands::kickCmd()
{
	std::string reason;
	if (this->_line_cmd.size() < 3)
	{
		this->_msg->ERR_NEEDMOREPARAMS(this->_fd_user);
		return;
	}
	if((this->_line_cmd[1][0] == '#') && chanExist(this->_line_cmd[1]) == true)
	{
		if (this->_s->getChannel(this->_line_cmd[1])->userIsInChann(this->_fd_user))
		{
			if (this->_s->getChannel(this->_line_cmd[1])->isOperator(this->_fd_user))
			{
				std::cout << " >> " <<  "Accepted : Channel Operator" << std::endl;
				if (this->_s->clientExist(this->_line_cmd[2]) && this->_s->getChannel(this->_line_cmd[1])->userIsInChann(this->_s->getClient(this->_line_cmd[2])->get_fd()) == true)
				{
					if(this->_line_cmd[2] == this->_s->getClient(this->_line_cmd[2])->getNickname())
					{
						if(joinMessages(3) == ": ")
							reason = "No Reason";
						else
							reason = joinMessages(3);
						std::map<int, Client*> UserCo = this->_s->getChannel(this->_line_cmd[1])->getListUserCo();
						for (std::map<int, Client*>::iterator it = UserCo.begin(); it != UserCo.end(); it++)
						{
							this->_msg->RPL_KICK(_user->getNickname(), _user->getUser(), this->_line_cmd[1], this->_s->getClient(this->_line_cmd[2])->getNickname(), reason, it->first);
						}
						std::cout << " >> " << this->_s->getClient(this->_line_cmd[2])->getNickname() << " is kicked from Channel " << this->_line_cmd[1] << std::endl;
						this->_s->getChannel(this->_line_cmd[1])->removeUser(this->_s->getClient(this->_line_cmd[2])->getNickname());
					}
				}
				else
				{
					this->_msg->ERR_USERNOTINCHANNEL(this->_user->getNickname(), this->_line_cmd[1], this->_fd_user);
					return ;
				}
			}
			else
			{
				std::cout << " >> " << "Denied : Not Channel Operator" << std::endl;
				this->_msg->ERR_CHANOPRIVSNEEDED(this->_user->getNickname(), this->_line_cmd[1], this->_fd_user);
				return ;
			}
		}
		else
			this->_msg->ERR_NOTONCHANNEL(this->_user->getNickname(), this->_line_cmd[1], this->_fd_user);
	}
	else
		this->_msg->ERR_NOSUCHCHANNEL(this->_line_cmd[1], this->_fd_user);
}
