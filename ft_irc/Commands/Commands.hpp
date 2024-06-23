#pragma once

#include "../Server.hpp"
# define BUFFER_SIZE 150

class Server;
class Messages;
class Channel;
class Client;

class Commands
{
	private :
		Messages*					_msg;
		Server* 					_s;
		Client*						_user;
		Client*						_bot;
		int							_fd_user;
		std::vector<std::string>	_line_cmd;
		char						_index;
		std::vector<char>			_optionList;

	public :
		Commands(Server *s, Client *c, int fd_c, std::vector<std::string> linecmd, Messages msg);
		~Commands();

		void						exec_cmd();
		bool						chanExist(std::string name_chan);
		void						cmdToConnect();

		char						getIndex();
		void						setIndex(char operand);

		// commands
		void						passCmd();
		void						userCmd();
		void						nickCmd();
		void						privMsgCmd();
		void						noticeCmd();
		void						joinCmd();
		void						quitCmd();
		void						inviteCmd();
		void						kickCmd();
		void						partCmd();
		void						topicCmd();
		// mode
		void						modeCmd();
		void						modeOnChannel();
		// mode on
		void						setChanInviteOnlyMode(); //i
		void						setChanRestrictTopic(); //t
		void						setChanKey(); //k
		void						setChanOperator(); //o
		void						setChanLimit(); //l
		int							verifModeParam();
		char						findIndex();
		void						splitOption();
		int							ft_stoi(std::string &s);
		int							verifUser();
		//utils
		Channel *					rplToAllChan();
		std::string					joinMessages(int line);
		void						leaveMultiChan();
		void						create_oa_join(std::string name_chann, std::string key);
		bool						userOnChannel();

		void 						setBot();
};
