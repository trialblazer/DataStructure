#ifndef QQ_H
#define QQ_H

#include "User.h"

#define Maxcount 6                  /// �û��˺Ŵ�С

class QQ {
public:
	QQ();
	User u[Maxcount];               ///�û�
	int user_size;                  ///�û�����
	int login();                    ///��½
	void regist();                  ///ע��
	void menue();
	void refresh();                 ///ˢ��
	int curr_order;                 ///��ǰ�û������û��еĴ���
};

#endif // QQ_H
