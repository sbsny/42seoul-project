#include "Commands.hpp"

void	Commands::modeOnChannel()
{
	if(verifModeParam() == 1)
		return;
	if(getIndex() == '\0')
		return;
	std::map<int, Client*> UserCo = this->_s->getChannel(this->_line_cmd[1])->getListUserCo();
	if(this->_s->getChannel(this->_line_cmd[1])->userIsInChann(this->_fd_user) == true)
	{
		for (std::map<int, Client*>::iterator it = UserCo.begin(); it != UserCo.end(); it++)
		{
			std::string	msg;
			if(this->_line_cmd.size() == 3)
				msg = ":" + this->_user->getNickname() + " " + this->_line_cmd[0] + " " + this->_line_cmd[1] + " " + this->_line_cmd[2] + "\r\n";
			else if (this->_line_cmd.size() == 4)
				msg = ":" + this->_user->getNickname() + " " + this->_line_cmd[0] + " " + this->_line_cmd[1] + " " + this->_line_cmd[2] + " " + this->_line_cmd[3] + "\r\n";
			send(it->first, msg.c_str(), msg.length(), 0);
		}
	}
	std::vector<char>::iterator	it = this->_optionList.begin();
	for(; it != this->_optionList.end(); ++it)
	{
		char option = *it;
		switch (option)
		{
			case 'i':
				setChanInviteOnlyMode();
				break;

			case 't' :
				setChanRestrictTopic();
				break;

			case 'k' :
				setChanKey();
				break;

			case 'o' :
				setChanOperator();
				break;

			case 'l' :
				setChanLimit();
				break;

			default:
				this->_msg->ERR_UMODUUNKNOWNFLAG(this->_line_cmd[0], this->_fd_user);
				break;
		}
	}
	return;
}

int		Commands::verifUser()
{
	std::vector<char>::iterator	it = this->_optionList.begin();
	for(; it != this->_optionList.end(); it++)
	{
		char	option = *it;
		if(option == 'o')
		{
			if(this->_line_cmd.size() == 3)
				return 1;
			if(getIndex() == '+' && this->_line_cmd.size() != 3)
			{
				if(!this->_s->getChannel(this->_line_cmd[1])->userIsInChan(this->_line_cmd[3]))
				{
					this->_msg->ERR_NOSUCHNICK(this->_line_cmd[3], this->_fd_user);
					this->_msg->ERR_USERNOTINCHANNEL(this->_line_cmd[3], this->_line_cmd[1], this->_fd_user);
					return 1;
				}
				else if(this->_s->getChannel(this->_line_cmd[1])->userIsInChan(this->_line_cmd[3]) && this->_s->getChannel(this->_line_cmd[1])->isOperator(this->_line_cmd[3]) == true)
					return 1;
			}
		}
	}
	return 0;
}

void	Commands::setChanInviteOnlyMode()
{
	if(this->getIndex() == '+')
	{
		if (this->_s->getChannel(this->_line_cmd[1])->isOperator(this->_fd_user) == false)
		{
			this->_msg->ERR_CHANOPRIVSNEEDED(_user->getNickname(), this->_line_cmd[1], this->_fd_user);
			std::cout << " >> " <<  this->_s->getClient(this->_line_cmd[3])->getNickname() << " are not Channel Operator " << std::endl;
			return ;
		}
		else
			this->_s->getChannel(this->_line_cmd[1])->setInviteOnly(true);
	}
	else if (this->getIndex() == '-')
	{
		if (this->_s->getChannel(this->_line_cmd[1])->isOperator(this->_fd_user) == false)
		{
			this->_msg->ERR_CHANOPRIVSNEEDED(_user->getNickname(), this->_line_cmd[1], this->_fd_user);
			std::cout << " >> " << this->_s->getClient(this->_line_cmd[3])->getNickname() << " are not Channel Operator " << std::endl;
			return ;
		}
		else
			this->_s->getChannel(this->_line_cmd[1])->setInviteOnly(false);
	}
}

void	Commands::setChanRestrictTopic(){

	if(this->getIndex() == '+')
		this->_s->getChannel(this->_line_cmd[1])->setTopicProtected(true);
	else if (this->getIndex() == '-')
		this->_s->getChannel(this->_line_cmd[1])->setTopicProtected(false);
}

void	Commands::setChanKey()
{
	if (this->_line_cmd.size() == 3)
		return ;
	if(this->getIndex() == '+')
		this->_s->getChannel(this->_line_cmd[1])->setKey(this->_line_cmd[3]);
	else if (this->getIndex() == '-')
		this->_s->getChannel(this->_line_cmd[1])->setKey("");
}

void	Commands::setChanOperator()
{
	if (this->getIndex() == '+')
	{
		this->_s->getChannel(this->_line_cmd[1])->addOperator(this->_s->getClient(this->_line_cmd[3]), this->_s->getClient(this->_line_cmd[3])->get_fd());
		std::cout << " >> " << this->_s->getClient(this->_line_cmd[3])->getNickname() << " is now Channel Operator " << std::endl;
	}
	else if (this->getIndex() == '-')
	{
		this->_s->getChannel(this->_line_cmd[1])->removeOperator(this->_line_cmd[3]);
		std::cout << " >> " << this->_s->getClient(this->_line_cmd[3])->getNickname() << " is removed of Channel Operators " << std::endl;
	}
}

void	Commands::setChanLimit()
{
	if (this->getIndex() == '-')
	{
		this->_s->getChannel(this->_line_cmd[1])->setSizeMax(-1);
		return ;
	}
	if (this->_line_cmd.size() == 3)
		return ;
	if(this->getIndex() == '+')
		this->_s->getChannel(this->_line_cmd[1])->setSizeMax(ft_stoi(this->_line_cmd[3]));
}
