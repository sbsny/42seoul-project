#pragma once

# include "Server.hpp"

class Commands;

class Client
{
	private :
		int			_fd;
		int			_pass_try;
		bool		_password;
		std::string	_nickname;
		std::string	_user;
		std::string _real_name;

    public :
        Client();
        ~Client();
		std::string	buffer;

		// Utils
		bool		isConnected();
		int			get_pass_try();
		void		increment_pass_try();

		// getters, setters
		std::string getRealname();
		void		setRealname(std::string user);
		bool		realnameIsSet();

		void		setNickname(std::string nickname);
		std::string getNickname();
		bool		nicknameIsSet();

		std::string getUser();
		void		setUser(std::string user);
		bool		userIsSet();

		bool		passwordIsSet();
		void		setPassword();

		int 		get_fd();
		void 		set_fd(int fd);
};
