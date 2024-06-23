#include "Commands.hpp"

std::string	Commands::joinMessages(int line)
{
	std::string msg;
	std::vector<std::string>::iterator it = this->_line_cmd.begin() + line;
	while (it != this->_line_cmd.end())
	{
		msg += *it;
		msg += " ";
		it++;
	}
	return(msg);
}

void	Commands::privMsgCmd()
{
	if (this->_line_cmd.size() < 3)
		this->_msg->ERR_NORECIPIENT(this->_fd_user);
	else if(this->_line_cmd.size() > 2)
	{
		if ((this->_line_cmd[1][0] == '#' || this->_line_cmd[1][0] == '&'))
		{
			if (chanExist(this->_line_cmd[1]) == true && this->_s->getChannel(this->_line_cmd[1])->userIsInChann(this->_fd_user) == true)
			{
				std::string msg = joinMessages(2);
				if (msg == ": ")
				{
					this->_msg->ERR_NOTEXTTOSEND(this->_fd_user);
					return ;
				}
				else
					this->_msg->RPL_PRIVMSGCHAN(this->_user->getNickname(), this->_line_cmd[1], msg, this->_s->getChannel(this->_line_cmd[1]), this->_fd_user);
			}
			else
			{
				this->_msg->ERR_CANNOTSENDTOCHAN(this->_line_cmd[1], this->_fd_user);
				return ;
			}
		}
		else if (this->_s->clientExist(this->_line_cmd[1]) == true)
		{
			if (joinMessages(2) == ": ")
			{
				this->_msg->ERR_NOTEXTTOSEND(this->_fd_user);
				return ;
			}
			else
			{
				this->_msg->RPL_PRIVMSG(this->_user->getNickname(), this->_line_cmd[1], joinMessages(2), this->_s->getClient(this->_line_cmd[1])->get_fd());
				return ;
			}
		}
		else
		{
			this->_msg->ERR_NOSUCHNICK(this->_line_cmd[1], this->_fd_user);
			return ;
		}
	}
}

void	Commands::noticeCmd()
{
	if (this->_line_cmd.size() < 3)
		this->_msg->ERR_NORECIPIENT(this->_fd_user);
	else if(this->_line_cmd.size() > 2)
	{
		if ((this->_line_cmd[1][0] == '#' || this->_line_cmd[1][0] == '&'))
		{
			if (chanExist(this->_line_cmd[1]) == true && this->_s->getChannel(this->_line_cmd[1])->userIsInChann(this->_fd_user) == true)
			{
				std::string msg = joinMessages(2);

				if (msg == ": ")
				{
					this->_msg->ERR_NOTEXTTOSEND(this->_fd_user);
					return ;
				}
				else
					this->_msg->RPL_PRIVMSGCHAN(this->_user->getNickname(), this->_line_cmd[1], msg, this->_s->getChannel(this->_line_cmd[1]), this->_fd_user);
			}
			else
			{
				this->_msg->ERR_CANNOTSENDTOCHAN(this->_line_cmd[1], this->_fd_user);
				return ;
			}
		}
		else if (this->_s->clientExist(this->_line_cmd[1]) == true)
		{
			if (joinMessages(2) == ": ")
			{
				this->_msg->ERR_NOTEXTTOSEND(this->_fd_user);
				return ;
			}
			else
			{
				this->_msg->RPL_NOTICE(this->_user->getNickname(), this->_line_cmd[1], joinMessages(2), this->_s->getClient(this->_line_cmd[1])->get_fd());
				return ;
			}
		}
		else
		{
			this->_msg->ERR_NOSUCHNICK(this->_line_cmd[1], this->_fd_user);
			return ;
		}
	}
}
