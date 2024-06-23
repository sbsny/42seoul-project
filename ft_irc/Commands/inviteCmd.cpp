#include "Commands.hpp"

void	Commands::inviteCmd()
{
	std::string	msg;

	if (this->_line_cmd.size() < 3)
	{
		this->_msg->ERR_NEEDMOREPARAMS(this->_fd_user);
		return ;
	}
	else if(_s->clientExist(this->_line_cmd[1]) == false)
	{
		this->_msg->ERR_NOSUCHNICK(this->_line_cmd[1], this->_fd_user);
		return ;
	}
	else if (!chanExist(this->_line_cmd[2]))
	{
		this->_msg->ERR_NOSUCHCHANNEL(this->_line_cmd[2], this->_fd_user);
		return ;
	}
	else if (!this->_s->getChannel(this->_line_cmd[2])->userIsInChann(this->_fd_user))
	{
		this->_msg->ERR_NOTONCHANNEL(this->_fd_user, this->_line_cmd[2]);
		return ;
	}
	else if (this->_s->getChannel(this->_line_cmd[2])->userIsInChann(this->_s->getClient(this->_line_cmd[1])->get_fd()))
	{
		this->_msg->ERR_USERONCHANNEL(this->_fd_user, this->_line_cmd[1], this->_line_cmd[2]);
		return ;
	}
	if (this->_s->getChannel(this->_line_cmd[2])->isOperator(this->_fd_user))
	{
		this->_msg->RPL_INVITING(_user->getNickname(), _user->getUser(), this->_s->getClient(this->_line_cmd[1])->getNickname(), this->_line_cmd[2], this->_fd_user);
		this->_msg->RPL_INVITE(_user->getNickname(), _user->getUser(), this->_s->getClient(this->_line_cmd[1])->getNickname(), this->_line_cmd[2], this->_s->getClient(this->_line_cmd[1])->get_fd());

		this->_s->getChannel(this->_line_cmd[2])->addListInv(this->_s->getClient(this->_line_cmd[1])->getNickname());
	}
	else
	{
		std::cout << "operator NOT" << std::endl;
		this->_msg->ERR_CHANOPRIVSNEEDED(this->_user->getNickname(), this->_line_cmd[2], this->_fd_user);
		return ;
	}

}
