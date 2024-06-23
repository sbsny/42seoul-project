#include "Commands.hpp"
// mode

void	Commands::modeCmd(){

	if (this->_line_cmd.size() == 1)
	{
		this->_msg->ERR_NEEDMOREPARAMS(this->_fd_user);
		return;
	}
	if (this->_line_cmd.size() == 2)
		return;
	if (this->_s->clientExist(this->_line_cmd[1]))
		return;
	else if (chanExist(this->_line_cmd[1]))
		modeOnChannel();
	else
	{
		this->_msg->ERR_NOSUCHNICK(this->_line_cmd[1], this->_fd_user);
		return ;
	}
}

char	Commands::findIndex()
{
	char	c = '\0';

	if(this->_line_cmd[2].size() == 1)
		return c;
	else
	{
		c = this->_line_cmd[2][0];
		if(isalpha(c) || isdigit(c))
			return '\0';
	}
	return c;
}

void		Commands::splitOption()
{
	for(int i = 0; i < (int)this->_line_cmd[2].size(); i++)
	{
		if((i == 0 && (this->_line_cmd[2][0] == '+' || this->_line_cmd[2][0] == '-')))
			continue;
		this->_optionList.push_back(this->_line_cmd[2][i]);
	}
}

int		Commands::ft_stoi(std::string &s)
{
	int i = 0;
	std::istringstream(s) >> i;
	return i;
}

int		Commands::verifModeParam()
{
	if(!chanExist(this->_line_cmd[1])){
		this->_msg->ERR_NOSUCHCHANNEL(this->_line_cmd[1], this->_fd_user);
		return 1;
	}
	if(!this->_s->getChannel(this->_line_cmd[1])->userIsInChann(this->_fd_user)) //user not on channel
	{
		this->_msg->ERR_NOTONCHANNEL(this->_user->getNickname(), this->_line_cmd[1], this->_fd_user);
		return 1;
	}
	if(!this->_s->getChannel(this->_line_cmd[1])->isOperator(this->_fd_user))
	{
		this->_msg->ERR_CHANOPRIVSNEEDED(this->_line_cmd[0], this->_fd_user);
		std::cout << " >> " << this->_user->getNickname() << " are not Channel Operator " << std::endl;
		return 1;
	}
	char index = findIndex();
	if( index != '+' && index != '-'){
		setIndex('\0');
		return 1;
	}
	this->setIndex(index);
	splitOption();
	if(verifUser() == 1)
		return 1;
	return 0;
}
