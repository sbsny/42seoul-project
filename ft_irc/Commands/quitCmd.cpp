#include "Commands.hpp"

bool	Commands::userOnChannel()
{
	int fd;
	std::map<std::string, Channel *> listChannel = this->_s->getListChan();
	std::map<int, Client*>	listClient = this->_s->getListClient();

	for (std::map<int, Client*>::iterator it = listClient.begin(); it != listClient.end(); it++)
	{
		fd = it->first;
		for (std::map<std::string, Channel *>::iterator it = listChannel.begin(); it != listChannel.end(); it++)
		{
			if (this->_s->getChannel(it->first)->userIsInChann(fd) == true)
				return true;
			else
				return false;
		}
	}
	return false;
}

Channel*	Commands::rplToAllChan()
{
	Channel *c;
	int fd;
	std::map<std::string, Channel *> listChannel = _s->getListChan();

	std::map<int, Client*>	listClient = _s->getListClient();

	for (std::map<int, Client*>::iterator it = listClient.begin(); it != listClient.end(); it++)
	{
		fd = it->first;
		for (std::map<std::string, Channel *>::iterator it = listChannel.begin(); it != listChannel.end(); it++)
		{
			if (this->_s->getChannel(it->first)->userIsInChann(fd) == true)
				c = this->_s->getChannel(it->first);
		}
	}
	return(c);
}

void	Commands::quitCmd()
{
	if(userOnChannel() == true)
	{
		this->_msg->RPL_QUIT(this->_user->getNickname(), this->_user->getUser(), joinMessages(1) , rplToAllChan());
		if (this->_user->nicknameIsSet() == false)
			std::cout << " >> " << "Client " << this->_fd_user << " has been disconnected." << std::endl;
		else
			std::cout << " >> " << this->_user->getNickname() << " has been disconnected." << std::endl;
		this->_s->setFdUsersDc(this->_fd_user);
	}
	else
	{
		if (this->_user->nicknameIsSet() == false)
			std::cout << " >> " << "Client " << this->_fd_user << " has been disconnected." << std::endl;
		else
			std::cout << " >> " << this->_user->getNickname() << " has been disconnected." << std::endl;
		this->_s->setFdUsersDc(this->_fd_user);
	}
}

