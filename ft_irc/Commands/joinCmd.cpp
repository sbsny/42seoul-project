#include "Commands.hpp"

void	Commands::create_oa_join(std::string name_chann, std::string key)
{
	std::string	msg;

	bool		chanExist = this->chanExist(name_chann);

	if (!chanExist)
	{
		Channel	*chan;

		if (!key.empty())
			chan = new Channel(name_chann, this->_user, key);
		else
			chan = new Channel(name_chann, this->_user);
		this->_s->addListChan(chan);
		std::cout << "Channel name: " << name_chann << " has been created by " << this->_s->getChannel(name_chann)->getCreator()->getNickname() << std::endl;
	}
	else
	{
		if (!this->_s->getChannel(name_chann)->getKey().empty() && key != this->_s->getChannel(name_chann)->getKey())
			this->_msg->ERR_CANNOTJOIN(this->_user->get_fd(), name_chann, 475);
		else if (this->_s->getChannel(name_chann)->getSizeMax() != -1 && this->_s->getChannel(name_chann)->nbUserInChan() >= this->_s->getChannel(name_chann)->getSizeMax())
			this->_msg->ERR_CANNOTJOIN(this->_user->get_fd(), name_chann, 471);
		else if (this->_s->getChannel(name_chann)->getInviteOnly() == true && this->_s->getChannel(name_chann)->isInv(this->_user->getNickname()) == false)
			this->_msg->ERR_CANNOTJOIN(this->_user->get_fd(), name_chann, 473);
		else
		{
			this->_s->getChannel(name_chann)->addUser(this->_user, this->_fd_user);
			std::cout << " >> " << this->_user->getNickname() << " has joined " << name_chann <<"\n";
		}
	}
	if (!this->_s->getChannel(name_chann)->userIsInChann(this->_user->get_fd()))
		return ;
	Channel*	c = this->_s->getChannel(name_chann);

	this->_msg->RPL_JOIN(this->_user->getNickname(), this->_user->getUser(), name_chann, c);
	if (!c->topicIsSet())
		this->_msg->RPL_NOTOPIC(c);
	else
		this->_msg->RPL_TOPIC(c);
	this->_msg->RPL_NAMREPLY(c, this->_user->get_fd());
	this->_msg->RPL_ENDOFNAMES(c, this->_user->get_fd(), this->_user->getNickname());
}


void	Commands::joinCmd()
{
	bool	key_empty = true;

	if (this->_line_cmd.size() > 2 && this->_line_cmd[2].empty() != 1)
			key_empty = false;
	if (this->_line_cmd.size() == 1)
		this->_msg->ERR_NEEDMOREPARAMS(this->_fd_user);
	if (this->_line_cmd[1].find(',') != std::string::npos)
	{
		std::string					tmp;
		std::vector<std::string>	split;
		unsigned long				e_i = 0;
		unsigned long				s_i = 0;
		std::vector<std::string>	list_chan = this->_s->splitCustom(this->_line_cmd[1], ',');
		std::vector<std::string>	list_key;
		if (key_empty == false)
		{
			for (unsigned long j = 0; j <= _line_cmd[2].size(); j++)
			{
				if (_line_cmd[2][j] == ',' || j == _line_cmd[2].size())
				{
					e_i = j;
					tmp.clear();
					tmp.append(_line_cmd[2], s_i, e_i - s_i);
					if (!tmp.empty())
						list_key.push_back(tmp);
					s_i = e_i + 1;
				}
			}
		}

		unsigned long long			i = 0;
		while (i < list_chan.size())
		{
			if (!key_empty && !list_key[i].empty())
				create_oa_join(list_chan[i], list_key[i]);
			else
				create_oa_join(list_chan[i], "");
			i++;
		}
	}
	else
	{
		if (!key_empty)
			create_oa_join(this->_line_cmd[1], this->_line_cmd[2]);
		else
			create_oa_join(this->_line_cmd[1], "");
	}
}
