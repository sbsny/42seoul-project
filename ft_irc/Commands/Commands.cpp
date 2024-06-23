#include "Commands.hpp"

Commands::Commands(Server *s, Client *c, int fd_c, std::vector<std::string> linecmd, Messages msg): _s(s), _user(c), _fd_user(fd_c), _line_cmd(linecmd)
{
	this->_msg = &msg;
}

Commands::~Commands(){}

void	Commands::exec_cmd()
{
	std::string	msg;

	if (this->_s->isCommandIrc(this->_line_cmd[0]) == false)
	{
		this->_msg->ERR_UNKNOWNCOMMAND(this->_line_cmd[0], this->_fd_user);
		return ;
	}
	if (this->_user->isConnected() == false) // user register
		cmdToConnect();
	else
	{
		if (this->_line_cmd[0] == "PASS")
			passCmd();
		else if (this->_line_cmd[0] == "USER")
			userCmd();
		else if (this->_line_cmd[0] == "NICK")
			nickCmd();
		else if (this->_line_cmd[0] == "PRIVMSG")
			privMsgCmd();
		else if (this->_line_cmd[0] == "JOIN")
			joinCmd();
		else if (this->_line_cmd[0] == "QUIT")
			quitCmd();
		else if (this->_line_cmd[0] == "NOTICE")
			noticeCmd();
		else if (this->_line_cmd[0] == "INVITE")
			inviteCmd();
		else if (this->_line_cmd[0] == "PART")
			partCmd();
		else if (this->_line_cmd[0] == "TOPIC")
			topicCmd();
		else if (this->_line_cmd[0] == "KICK")
			kickCmd();
		else if (this->_line_cmd[0] == "MODE")
			modeCmd();
		else if (this->_line_cmd[0] == "WHOIS")
			return ;
		else if (this->_line_cmd[0] == "WHO")
			return ;
		else if (this->_line_cmd[0] == "PING")
		{
			std::string msg = ":localhost PONG :localhost\r\n";
			send(this->_fd_user, msg.c_str(), msg.size(), 0);
		}
	}
}

// Commands to connects

void	Commands::cmdToConnect()
{
	if (this->_line_cmd[0] == "PASS")
		passCmd();
	else if (_line_cmd[0] == "USER" && this->_user->passwordIsSet() == true)
		userCmd();
	else if (_line_cmd[0] == "NICK" && this->_user->passwordIsSet() == true)
		nickCmd();
	else if(_line_cmd[0] != "CAP")
		this->_msg->ERR_NOTREGISTERED(this->_fd_user);

	if (this->_user->isConnected())
		this->_msg->welcome(this->_user, this->_fd_user);
}

// CHANNELS

bool	Commands::chanExist(std::string name_chan)
{
	std::map<std::string, Channel*> map = this->_s->getListChan();
	std::map<std::string, Channel*>::iterator it = map.begin();

	if (!map.empty())
	{
		while (it != map.end())
		{
			if (it->first == name_chan)
				return (true);
			it++;
		}
	}
	return (false);
}

char	Commands::getIndex(){
	return this->_index;
}

void	Commands::setIndex(char operand){
	this->_index = operand;
}

