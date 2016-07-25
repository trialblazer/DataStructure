#ifndef QQ_H
#define QQ_H

#include "User.h"

#define Maxcount 6                  /// 用户账号大小

class QQ {
public:
	QQ();
	User u[Maxcount];               ///用户
	int user_size;                  ///用户个数
	int login();                    ///登陆
	void regist();                  ///注册
	void menue();
	void refresh();                 ///刷新
	int curr_order;                 ///当前用户在总用户中的次序
};

#endif // QQ_H
