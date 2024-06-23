#pragma once

#include "Server.hpp"
#include "Client.hpp"

class Server;
class Client;

class Channel
{
	private:
		std::string					_name;
		Client*						_creator;
		std::string					_key;
		std::string					_topic;
		std::map<int, Client *>		_list_user_co;
		std::map<int, Client *>		_list_operators;
		std::string					_password;
		int							_size_max;
		bool						_i_only;
		bool						_topicProtected; //topic
		std::vector<std::string>	_list_inv;
		Client*						_bot;

	public:
		Channel(std::string name, Client* c);
		Channel(std::string name,  Client* c, std::string key);
		virtual	~Channel();

		Channel*	operator=(Channel const *c);

		bool	userIsInChan(std::string nickname);
		bool	isOperator(std::string nickname);

		void	displayUsers();
		void	displayOp();
		bool	userIsInChann(int user);
		void	sendMsg(int user_talk, std::string msg);
		bool	isOperator(int fd);
		int		nbUserInChan();
		bool	isInv(std::string nickname);


		std::string					getName();
		void						setName(std::string name);

		std::map<int, Client*>		getListUserCo();
		void						addUser(Client *cl, int fd_cl);
		void						removeUser(std::string username);

		std::map<int, Client*>		getListOp();
		void						addOperator(Client *cl, int fd_cl);
		void						removeOperator(std::string username);

		std::string					getTopic() const;
		void						setTopic(std::string topic);
		bool						topicIsSet();
		void						unsetTopic(std::string topic);

		std::string					getKey() const;
		void						setKey(std::string key);

		int							getSizeMax() const;
		void						setSizeMax(int size);

		void						setInviteOnly(bool set);
		bool						getInviteOnly() const;

		std::vector<std::string>	getListInv();
		void						addListInv(std::string nickname);
		void						removeListInv(std::string nickname);

		bool						getTopicProtected() const;
		void						setTopicProtected(bool protect);

		Client*						getCreator();

		void						setBot();

};
