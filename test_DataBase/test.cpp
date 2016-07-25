#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>

//#include <stl_algo.h>

using namespace std;

struct Stu {
	string sno;
	string sname;
	unsigned short sage;
	string sex;

	bool operator==(const string& sno)const {
		return this->sno == sno;
	}
};

struct Cou {
	string cno;
	string cname;

	bool operator==(const string& cno)const {
		return this->cno == cno;
	}
};

struct Sc {
	string sno;
	string cno;
	unsigned int grade;
};



struct ResultView1 {
	string sno;
	string sname;
	map<string, unsigned int>mapGrade;  //课程，成绩
};

struct ResultView3 {
	string cno;
	string cname;
	float average;

	bool operator< (const ResultView3& rv)const {
		bool bRet = false;
		if (average < rv.average)
			bRet = true;
		else {
			if (average == rv.average)
				bRet = cno>rv.cno ? true : false;
		}
		return bRet;
	}

};

struct ResultView4 {
	string cno;
	vector<string> vs;
};


class MyCompare1 {
	string sno;

public:
	MyCompare1(string sno) {
		this->sno = sno;
	}
	bool operator () (const Sc& s)const {
		return sno != s.sno;
	}
};


class Mycompare2 {
public:
	bool operator() (const Sc& s1, const Sc& s2) const {
		return s1.sno < s2.sno;
	}
};

class Mycompare3 {  //成绩向量按课程号升序排列接口
public:
	float operator() (const Sc& s1, const Sc& s2) const {
		return s1.cno<s2.cno;
	}
};

class Mycompare4 {
public:
	bool operator () (const Sc& s1, const Sc& s2) const {
		bool bRet = false;
		if (s1.cno < s2.cno)
			bRet = true;
		else {
			if (s1.cno == s2.cno)
				bRet = s1.grade > s2.grade ? true : false;
		}
		return bRet;
	}
};

class Mycompare42 {
	string cno;

public:
	Mycompare42(string cno) {
		this->cno = cno;
	}
	bool operator()(const Sc& s) const {
		return cno == s.cno;
	}
};


class Mycompare43 {
public:
	bool operator () (const Sc& s1, const Sc& s2) const {
		return s1.grade >= s2.grade;
	}
};
class MySum3 {    //accumulate函数调用接口
public:
	float operator() (const float& result, const Sc& s) const {
		return result + s.grade;
	}
};


class Find {
	vector<Stu> & _vs;
	vector<Cou> & _vc;
	vector<Sc> & _vsc;

public:
	Find(vector<Stu>& vs, vector<Cou>&vc, vector<Sc>& vsc) :_vs(vs), _vc(vc), _vsc(vsc) {}
	bool getFactor1Result(string sno, ResultView1& v) {
		vector<Stu>::iterator it = find(_vs.begin(), _vs.end(), sno);
		if (it == _vs.end())
			return false;
		v.sno = it->sno;
		v.sname = it->sname;

		vector<Sc> vec;
		//back_inserter 是iterator适配器，它使得元素被插入到作为实参的某种容器的尾部，如vector等
		remove_copy_if(_vsc.begin(), _vsc.end(), back_inserter(vec), MyCompare1(sno));
		for (unsigned int i = 0; i<vec.size(); i++) {
			vector<Cou>::iterator it = find(_vc.begin(), _vc.end(), vec[i].cno);
			pair<string, unsigned int>p(it->cname, vec[i].grade);
			v.mapGrade.insert(p);
		}
		return true;
	}

	bool getFactor2Result(vector<string>& vResult) {
		int nCount = _vc.size();
		sort(_vsc.begin(), _vsc.end(), Mycompare2());

		int pos = 0;
		typedef vector<Sc>::iterator FwdIt;
		FwdIt begin = _vsc.begin();
		pair<FwdIt, FwdIt> it;
		while (begin != _vsc.end()) {
			it = equal_range(begin, _vsc.end(), _vsc[pos], Mycompare2());
			int nSize = it.second - it.first;
			if (nSize == nCount) {
				FwdIt pSc = it.first;
				vResult.push_back(pSc->sno);
			}
			pos += nSize;
			begin = it.second;
		}
		return true;
	}
	bool getFactor22Result(vector<string>& vResult) {
		map<string, int> mymap;  //学号-课程数
		map<string, int>::iterator it;
		pair<string, int> p;

		for (unsigned int i = 0; i<_vsc.size(); i++) {
			if (mymap.empty()) {
				p.first = _vsc[0].sno;
				p.second = 1;
				mymap.insert(p);
			}
			else {
				it = mymap.find(_vsc[i].sno);
				if (it == mymap.end()) {
					p.first = _vsc[i].sno;
					p.second = 1;
					mymap.insert(p);
				}
				else
					it->second++;
			}
		}

		int nCount = _vc.size();
		it = mymap.begin();
		while (it != mymap.end()) {
			if (it->second == nCount)
				vResult.push_back(it->first);
			it++;
		}
		return true;
	}

	bool getFactor3Result(vector<ResultView3> & vResult) {
		sort(_vsc.begin(), _vsc.end(), Mycompare3()); //课程号升序排序
		typedef vector<Sc>::iterator MyIt;
		pair<MyIt, MyIt> p;
		MyIt begin = _vsc.begin();

		ResultView3 rv3;
		while (begin != _vsc.end()) {
			p = equal_range(begin, _vsc.end(), *begin, Mycompare3());
			rv3.cno = begin->cno;
			rv3.average = accumulate(p.first, p.second, 0.0f, MySum3());
			vResult.push_back(rv3);
			begin = p.second;
		}
		sort(vResult.begin(), vResult.end());
		return true;
	}
	
	bool getFactor4Result(vector<ResultView4>& vResult) {
		sort(_vsc.begin(), _vsc.end(), Mycompare4());  //按课程号升序，成绩降序排列
		typedef vector<Sc>::iterator MyIt;
		pair<MyIt, MyIt> p;
		MyIt begin = _vsc.begin();
		while (begin != _vsc.end()) {
			p = equal_range(begin, _vsc.end(), *begin, Mycompare3());
			ResultView4 rv;
			rv.cno = begin->cno;
			rv.vs.push_back(begin->sno);
			begin++;
			rv.vs.push_back(begin->sno);

			vResult.push_back(rv);
			begin = p.second;
		}
		return true;
	}
	bool getFactor42Result(vector<ResultView4>& vResult) {
		typedef vector<Sc>::iterator MyIt;
		MyIt begin = _vsc.begin();

		while (begin != _vsc.end()) {
			MyIt mid = partition(begin, _vsc.end(), Mycompare42(begin->cno));
			partial_sort(begin, begin + 2, mid, Mycompare43());
			//或者nth_element(begin, begin+2, mid, Mycompare43());

			ResultView4 rv;
			rv.cno = begin->cno;
			rv.vs.push_back(begin->sno);
			begin++;
			rv.vs.push_back(begin->sno);
			vResult.push_back(rv);
			begin = mid;
		}
		return true;
	}
};


#include <assert.h>

class TestFind {
	vector<Stu> vecStu;
	vector<Cou> vecCou;
	vector<Sc> vecSc;

public:
	TestFind() {
		ifstream in("stud.txt");
		Stu s;
		assert(in.is_open());
		while (!in.eof()) {
			in >> s.sno >> s.sname >> s.sex;
			vecStu.push_back(s);
		}
		in.close();
		ifstream in2("cour.txt");
		assert(in2.is_open());
		Cou c;
		while (!in2.eof()) {
			in2 >> c.cno >> c.cname;
			vecCou.push_back(c);
		}
		in2.close();

		ifstream in3("grade.txt");
		assert(in3.is_open());
		Sc sc;
		while (!in3.eof()) {
			in3 >> sc.cno >> sc.cno >> sc.grade;
			vecSc.push_back(sc);
		}
		in3.close();
}
	void find() {
		Find obj(vecStu, vecCou, vecSc);

		ResultView1 rv1;
		obj.getFactor1Result("1001", rv1);
		cout << rv1.sno << "\t" << rv1.sname << endl;
		map<string, unsigned int>::iterator it = rv1.mapGrade.begin();
		while (it != rv1.mapGrade.end()) {
			cout << "\t" << it->first << "\t" << it->second << endl;
			it++;
		}
	}

};

int main() {
	TestFind tf;
	tf.find();

	return 0;
}