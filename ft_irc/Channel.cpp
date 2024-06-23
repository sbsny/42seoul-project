#include "Channel.hpp"

Channel::Channel(std::string name, Client* c): _name(name), _creator(c), _key(),
											_topic(), _list_user_co(), _list_operators(),
											_password(), _size_max(10),
											_i_only(false), _list_inv()
{
	setBot();
	this->addUser(c, c->get_fd());
	this->addOperator(c, c->get_fd());
	this->addUser(this->_bot, this->_bot->get_fd());
	this->addOperator(this->_bot, this->_bot->get_fd());
}

Channel::Channel(std::string name,  Client* c, std::string key): _name(name), _creator(c), _key(key),
																_topic(), _list_user_co(), _list_operators(),
																_password(), _size_max(10),
																_i_only(false), _list_inv()
{
	setBot();
	this->addUser(c, c->get_fd());
	this->addOperator(c, c->get_fd());
	this->addUser(this->_bot, this->_bot->get_fd());
	this->addOperator(this->_bot, this->_bot->get_fd());
}

Channel::~Channel()
{
	delete this->_bot;
}

Channel*	Channel::operator=(Channel const *c)
{
	this->_name = c->_name;
	this->_creator = c->_creator;
	this->_key = c->_key;
	this->_topic = c->_topic;
	this->_list_user_co = c->_list_user_co;
	this->_list_operators = c->_list_operators;
	this->_password = c->_password;
	return (this);
}

void						Channel::setBot()
{
	this->_bot = new Client();

	this->_bot->setNickname("42Bot1");
	this->_bot->setUser("42Bot2");
	this->_bot->setRealname("42Bot3");
	this->_bot->setPassword();
	this->_bot->set_fd(0);

}

void	Channel::displayUsers()
{
	for (std::map<int, Client *>::iterator it = this->_list_user_co.begin(); it != this->_list_user_co.end(); it++)
	{
		if (!it->second->getNickname().empty())
			std::cout << "- " << ((it->second->getNickname().empty()) ? it->second->getUser() : it->second->getNickname()) << std::endl;
	}
}

void	Channel::displayOp()
{
	for (std::map<int, Client *>::iterator it = this->_list_operators.begin(); it != this->_list_operators.end(); it++)
	{
		if (!it->second->getNickname().empty())
			std::cout << "- " << ((it->second->getNickname().empty()) ? it->second->getUser() : it->second->getNickname()) << std::endl;
	}
}

bool	Channel::userIsInChann(int user)
{
	for (std::map<int, Client*>::iterator it = this->_list_user_co.begin(); it != this->_list_user_co.end(); it++)
		if (it->first == user)
			return (true);
	return (false);
}

void	Channel::sendMsg(int user_talk, std::string msg)
{
	for (std::map<int, Client*>::iterator it = this->_list_user_co.begin(); it != this->_list_user_co.end(); it++)
		if (it->first != user_talk && it->first != 0)
			send(it->first, msg.c_str(), msg.size(), 0);
}

bool	Channel::isOperator(int fd)
{
	for (std::map<int, Client *>::iterator itop = this->_list_operators.begin(); itop != this->_list_operators.end(); itop++)
	{
		if (itop->first == fd)
			return (true);
	}
	return (false);
}

int		Channel::nbUserInChan()
{
	int	i = 0;
	for (std::map<int, Client*>::iterator it = this->_list_user_co.begin(); it != this->_list_user_co.end(); it++)
		i++;
	return (i);
}

bool	Channel::isInv(std::string nickname)
{
	if (!this->_list_inv.empty())
	{
		for (std::vector<std::string>::iterator it = this->_list_inv.begin(); it != this->_list_inv.end(); it++)
		{
			if (*it == nickname)
				return (true);
		}
	}
	return (false);
}

std::string	Channel::getName()
{
	return (this->_name);
}

void		Channel::setName(std::string name)
{
	this->_name = name;
}

std::map<int, Client*>	Channel::getListUserCo()
{
	return (this->_list_user_co);
}

void					Channel::addUser(Client *cl, int fd_cl)
{
	if (this->_i_only && !this->isInv(cl->getNickname()))
		return ;
	this->_list_user_co.insert(std::pair<int, Client*>(fd_cl, cl));
}

void					Channel::removeUser(std::string username)
{
	for (std::map<int, Client *>::iterator it = this->_list_user_co.begin(); it != this->_list_user_co.end(); it++)
	{
		if (it->second->getUser() == username || it->second->getNickname() == username)
		{
			if (isInv(it->second->getNickname()))
			{
				this->removeListInv(username);
			}
			this->_list_user_co.erase(it->first);
			return ;
		}
	}
}

std::map<int, Client*>	Channel::getListOp()
{
	return (this->_list_operators);
}

void					Channel::addOperator(Client *cl, int fd_cl)
{
	this->_list_operators.insert(std::pair<int, Client*>(fd_cl, cl));
}

void					Channel::removeOperator(std::string username)
{
	for (std::map<int, Client *>::iterator it = this->_list_operators.begin(); it != this->_list_operators.end(); it++)
	{
		if (it->second->getUser() == username || it->second->getNickname() == username)
		{
			this->_list_operators.erase(it->first);
			return ;
		}
	}
}

std::string	Channel::getTopic() const
{
	return (this->_topic);
}

void		Channel::setTopic(std::string topic)
{
	this->_topic = topic;
}

void		Channel::unsetTopic(std::string topic)
{
	this->_topic = topic;
}

bool		Channel::topicIsSet()
{
	if(this->_topic.empty())
		return false;
	else
		return true;
}

std::string	Channel::getKey() const
{
	return (this->_key);
}

void		Channel::setKey(std::string key)
{
	this->_key = key;
}

int	Channel::getSizeMax() const
{
	return (this->_size_max);
}

void	Channel::setSizeMax(int size)
{
	this->_size_max = size;
}

std::vector<std::string>	Channel::getListInv()
{
	return (this->_list_inv);
}

void						Channel::addListInv(std::string nickname)
{
	this->_list_inv.push_back(nickname);
}

void						Channel::removeListInv(std::string nickname)
{
	if (!this->_list_inv.empty())
	{
		for (std::vector<std::string>::iterator it = this->_list_inv.begin(); it != this->_list_inv.end(); it++)
		{
			if (*it == nickname)
			{
				this->_list_inv.erase(it);
				return ;
			}
		}
	}
}

Client*	Channel::getCreator()
{
	return (this->_creator);
}

bool	Channel::getInviteOnly() const
{
	return this->_i_only;
}

void	Channel::setInviteOnly(bool set){

	this->_i_only = set;
}

bool	Channel::getTopicProtected() const
{
	return this->_topicProtected;
}

void	Channel::setTopicProtected(bool protect)
{
	this->_topicProtected = protect;
}

bool	Channel::userIsInChan(std::string nickname)
{
	std::map<int, Client *>::iterator	it = this->_list_user_co.begin();
	for(; it != this->_list_user_co.end(); it++)
	{
		if(nickname == it->second->getNickname())
			return true;
	}
	return false;
}

bool	Channel::isOperator(std::string nickname)
{
	std::map<int, Client *>::iterator	it = this->_list_operators.begin();
	for(; it != this->_list_operators.end(); it++)
	{
		if(nickname == it->second->getNickname())
			return true;
	}
	return false;
}
