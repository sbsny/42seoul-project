#include "Commands.hpp"

void	Commands::leaveMultiChan()
{
	std::vector<std::string> channels = _s->splitCustom(this->_line_cmd[1], ',');

	for(unsigned int i = 0; i < channels.size(); i++)
	{
		if ((channels[i][0] == '#') && chanExist(channels[i]) == true)
		{
			std::map<int, Client*> UserCo = this->_s->getChannel(channels[i])->getListUserCo();
			if(this->_s->getChannel(channels[i])->userIsInChann(this->_fd_user) == true)
			{
				for (std::map<int, Client*>::iterator it = UserCo.begin(); it != UserCo.end(); it++)
				{
					this->_msg->RPL_LEFTCHANNEL(this->_user->getNickname(), this->_user->getUser(), channels[i], it->first);
				}
				this->_s->getChannel(channels[i])->removeUser(_user->getNickname());
				std::cout << " >> " << this->_user->getNickname() << " has left channel " << channels[i] << std::endl;
			}
			else
				this->_msg->ERR_NOTONCHANNEL(this->_user->getNickname(), channels[i], this->_fd_user);
		}
		else
		{
			this->_msg->ERR_NOSUCHCHANNEL(this->_line_cmd[1], this->_fd_user);
			return ;
		}
	}
}

void	Commands::partCmd()
{
	std::string::iterator searchMulti = find(this->_line_cmd[1].begin(), this->_line_cmd[1].end(), ',');
	if (this->_line_cmd.size() < 1)
	{
		this->_msg->ERR_NEEDMOREPARAMS(this->_fd_user);
		return ;
	}
	if(*searchMulti == ',')
	{
		leaveMultiChan();
		return ;
	}
	if ((this->_line_cmd[1][0] == '#') && chanExist(this->_line_cmd[1]) == true && *searchMulti != ',')
	{
		std::map<int, Client*> UserCo = this->_s->getChannel(this->_line_cmd[1])->getListUserCo();
		if(this->_s->getChannel(this->_line_cmd[1])->userIsInChann(this->_fd_user) == true)
		{
			for (std::map<int, Client*>::iterator it = UserCo.begin(); it != UserCo.end(); it++)
			{
				this->_msg->RPL_LEFTCHANNEL(this->_user->getNickname(), this->_user->getUser(), this->_line_cmd[1], it->first);
			}
			this->_s->getChannel(this->_line_cmd[1])->removeUser(this->_user->getNickname());
			std::cout << " >> " <<  this->_user->getNickname() << " has left channel " << this->_line_cmd[1] << std::endl;
		}
		else
			this->_msg->ERR_NOTONCHANNEL(this->_user->getNickname(), this->_line_cmd[1], this->_fd_user);
	}
	else
	{
		this->_msg->ERR_NOSUCHCHANNEL(this->_line_cmd[1], this->_fd_user);
		return ;
	}
	if (this->_s->getChannel(this->_line_cmd[1])->getListUserCo().size() == 1)
       this->_s->channDisconnected();
}
