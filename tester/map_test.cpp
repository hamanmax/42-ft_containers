#include "tester.hpp"


void test_map_constructor_capacity(){
	std::cout << BOLD << LIGHTBLUE << "Testing map constructor" << END << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ismap t;
	std::allocator<ispair> alloc = t.get_allocator();
	std::cout << "get_allocator :" << std::endl;
	ispair *p = alloc.allocate(1,NULL);
	alloc.construct(p,ispair(0,std::string("Coucou")));
	std::cout << p->first << " " << p->second << " " << std::endl;
	std::cout << "Default Constructors :" << std::endl;
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << t.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (t.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl;
	std::cout << "Range constructor with a range of pair :" << std::endl;
	ispair range[5] = {ispair(0,"Bonjour"),ispair(1,"Hello"),ispair(2,"Salut"),ispair(3,"Coucou"),ispair(4,"Aloa")};
	ismap t3(range,range + 5);
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << t3.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (t3.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << t3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = t3.begin(); it != t3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Copy constructor with a range of pair reverse elem :" << std::endl;
	ismap t4(t3);
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << t4.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (t4.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << t4.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::reverse_iterator it = t4.rbegin(); it != t4.rend(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	alloc.destroy(p);
	alloc.deallocate(p,1);
}

void test_map_element_access(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing map element access" << END << std::endl;
	std::cout << "Testing operator[] in a bunch of situation :" << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ispair range[5] = {ispair(0,"Bonjour"),ispair(1,"Hello"),ispair(2,"Salut"),ispair(3,"Coucou"),ispair(4,"Aloa")};
	ismap t(range,range + 5);
	std::cout << str << "empty\t\t" << END << (t.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = t.begin(); it != t.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Modifying the value of the pairs :" << std::endl;
	t[0] = std::string("Un");
	t[1] = std::string("jour");
	t[2] = std::string("je");
	t[3] = std::string("serait");
	t[4] = std::string("le");
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = t.begin(); it != t.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Adding pairs of data :" << std::endl;
	t[5] = std::string("meilleur");
	t[6] = std::string("dresseur");
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::iterator i = t.begin(); i != t.end(); i++){
	std::cout << t.at(i->first) << " ";}std::cout << END << std::endl;
}

void test_map_iterators()
{
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	std::cout << BOLD << LIGHTBLUE << std::endl << "Testing map iterators implementation" << END << std::endl;
	ispair range[5] = {ispair(0,"Bonjour"),ispair(1,"Hello"),ispair(2,"Salut"),ispair(3,"Coucou"),ispair(4,"Aloa")};
	ismap t(range,range + 5);
	ismap t2(t);
	ismap t3;
	ismap::iterator it1 = t.begin();
	ismap::iterator ite1 = t.end();
	ismap::const_iterator cit1 = t.begin();
	ismap::const_iterator cite1 = t.end();
	ismap::reverse_iterator rit1 = t.rbegin();
	ismap::reverse_iterator rite1 = t.rend();
	ismap::const_reverse_iterator crit1 = t.rbegin();
	ismap::const_reverse_iterator crite1 = t.rend();
	std::cout << "Tesing begin and end iterator : ";
	std::cout <<LIGHTORANGE << it1->first << " " << (--ite1)->first << " " << cit1->first << " " << (--cite1)->first << " " << rit1->first << " " << (--rite1)->first << " "  << crit1->first << " " << (--crite1)->first << END << std::endl;
	ite1++;
	cite1++;
	rite1++;
	crite1++;
	std::cout << "Testing iterator equality operators t1 and t2 begin :" << std::endl;
	print_map_operator("Map",t.begin(),t2.begin());
	std::cout << "Testing iterator equality operators t2 and t2 begin :" << std::endl;
	print_map_operator("Map",t.begin(),t.begin());
	std::cout << "Testing iterator equality operators t3 and t3 begin :" << std::endl;
	print_map_operator("Map",t3.begin(),t3.begin());
	std::cout << "Testing normal iterator begin to end :" << std::endl;
	std::cout << str << "elements\t" << END << "= " << LIGHTORANGE;
	for (; it1 != ite1; ++it1){
	std::cout << it1->first << "|" << it1->second << " ";}std::cout << END << std::endl;

	std::cout << "Testing const iterator begin to end :" << std::endl;
	std::cout << str << "elements\t" << END << "= " << LIGHTORANGE;
	for (; cit1 != cite1; ++cit1){
	std::cout << cit1->first << "|" << cit1->second << " ";}std::cout << END << std::endl;

	std::cout << "Testing reverse iterator begin to end :" << std::endl;
	std::cout << str << "elements\t" << END << "= " << LIGHTORANGE;
	for (; rit1 != rite1; ++rit1){
	std::cout << rit1->first << "|" << rit1->second << " ";}std::cout << END << std::endl;

	std::cout << "Testing const reverse iterator begin to end :" << std::endl;
	std::cout << str << "elements\t" << END << "= " << LIGHTORANGE;
	for (; crit1 != crite1; ++crit1){
	std::cout << crit1->first << "|" << crit1->second << " ";}std::cout << END << std::endl;
}

void test_map_clear(){
	std::cout << "Testing clear function :" << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ispair range[5] = {ispair(0,"Bonjour"),ispair(1,"Hello"),ispair(2,"Salut"),ispair(3,"Coucou"),ispair(4,"Aloa")};
	ismap i(range,range + 5);
	ismap i2(i);
	ismap i3(i);
	for (int i = 8; i < 16; i++)
		i3.insert(ispair(i,std::string("Hey")));
	std::cout << "i before clear :" << std::endl;
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i.size() << END << std::endl;
	std::cout << "i after clear :" << std::endl;
	i.clear();
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i.size() << END << std::endl;
	std::cout << "i2 before clear :" << std::endl;
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i2.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i2.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i2.size() << END << std::endl;
	std::cout << "i2 after clear :" << std::endl;
	i2.clear();
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i2.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i2.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i2.size() << END << std::endl;
	std::cout << "i3 before clear :" << std::endl;
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i3.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i3.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << "i3 after clear :" << std::endl;
	i3.clear();
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i3.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i3.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;

}

void test_map_insert(){
	std::cout << BOLD << UNDERLINE << std::endl << "Testing map insert" << END << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ismap i3;
	for (int i = 0; i < 20; i+=2)
		i3.insert(ispair(i,std::string("Hey")));
	ismap::iterator it = i3.begin();
	it++;it++;it++;
	std::cout << "Insert with a value :" << std::endl;
	#ifdef NAMESPACE
	NAMESPACE::pair<ismap::iterator,bool> pb(i3.insert(ispair(15,std::string("Nouveau"))));
	#else
	ft::pair<ismap::iterator,bool> pb(i3.insert(ispair(15,std::string("Nouveau"))));
	#endif
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "return_value\t" << END << "= " << LIGHTORANGE << pb.first->first << "|" << pb.first->second << "\t" << (pb.second?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END) << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "Insert with a value n2:" << std::endl;
	#ifdef NAMESPACE
	NAMESPACE::pair<ismap::iterator,bool> pbe(i3.insert(ispair(14,std::string("Nouveaudeux"))));
	#else
	ft::pair<ismap::iterator,bool> pbe(i3.insert(ispair(14,std::string("Nouveaudeux"))));
	#endif
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "return_value\t" << END << "= " << LIGHTORANGE << pbe.first->first << "|" << pbe.first->second << "\t" << (pbe.second?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END) << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "Insert with a hint :" << std::endl;
	ismap::iterator it2 = i3.insert(it,ispair(7,std::string("Bonjour")));
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "return_value\t" << END << "= " << LIGHTORANGE << it2->first << "|" << it2->second << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	ispair range[8];
	for (int i = 0; i < 8; ++i){
		range[i].first = i+i+1;
		range[i].second = std::string("Encore");
	}
	std::cout << "Insert with a range :" << std::endl;
	i3.insert(range,range + 8);
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
}

void test_map_erase(){
	std::cout << BOLD << UNDERLINE << std::endl << "Testing map erase :" << END << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ismap i3;
	for (int i = 0; i < 20; i+=2)
		i3.insert(ispair(i,std::string("Hey")));
	std::cout << "erase the first (0) with his pos and the second with his key (14)" << std::endl;
	std::cout << "Before erasing :" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	i3.erase(i3.begin());
	i3.erase(14);
	std::cout << "After erasing :" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "erase a range of pair from begin to end - 3:" << std::endl;
	std::cout << "Before erasing :" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	ismap::iterator it2 = --(--(--i3.end()));
	i3.erase(i3.begin(), it2);
	std::cout << "After erasing :" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
}

void test_map_swap(){
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ismap m;
	ismap m2;
	for (int i = 1; i < 20; i+=2)
		m2.insert(ispair(i,std::string("Hey")));
	ismap m3;
	for (int i = 0; i < 20; i+=2)
		m3.insert(ispair(i,std::string("Hey")));

	std::cout << BOLD << UNDERLINE << std::endl << "Testing mumber function swap" << END << std::endl;

	std::cout << "Swapping m2 and m3" << std::endl;
	std::cout << "Befrore m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	m2.swap(m3);
	std::cout << "After m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "Swapping m3 and m" << std::endl;

	std::cout << "Befrore m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	m3.swap(m);
	std::cout << "After m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;


	std::cout << "Swapping m and m2" << std::endl;
	std::cout << "Befrore m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "After m:" << std::endl;
	m.swap(m2);
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
}

void test_map_count(){
	ismap m_odd;
	for (int i = 1; i < 20; i+=2)
		m_odd.insert(ispair(i,std::string("Hisse")));
	ismap m_even;
	for (int i = 0; i < 20; i+=2)
		m_even.insert(ispair(i,std::string("Oh")));
	ismap m_total(m_even);
	m_total.insert(m_odd.begin(),m_odd.end());
	std::cout << BOLD << UNDERLINE << "Testing member function count :" << END << std::endl;
	std::cout << "m_odd : ";
	for (ismap::const_iterator it = m_odd.begin(); it != m_odd.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_odd map :" << (m_odd.count(4)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_odd map :" << (m_odd.count(9)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_odd map :" << (m_odd.count(1)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_odd map :" << (m_odd.count(7)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_odd map :" << (m_odd.count(0)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_odd map :" << (m_odd.count(2)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << std::endl << "m_even :";for (ismap::const_iterator it = m_even.begin(); it != m_even.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_even map :" << (m_even.count(4)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_even map :" << (m_even.count(9)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_even map :" << (m_even.count(1)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_even map :" << (m_even.count(7)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_even map :" << (m_even.count(0)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_even map :" << (m_even.count(2)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << std::endl << "m_total : ";for (ismap::const_iterator it = m_total.begin(); it != m_total.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_total map :" << (m_total.count(4)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_total map :" << (m_total.count(9)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_total map :" << (m_total.count(1)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_total map :" << (m_total.count(7)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_total map :" << (m_total.count(0)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_total map :" << (m_total.count(2)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
}

void test_map_find(){
	ismap m_odd;
	for (int i = 1; i < 20; i+=2)
		m_odd.insert(ispair(i,std::string("Hisse")));
	ismap m_even;
	for (int i = 0; i < 20; i+=2)
		m_even.insert(ispair(i,std::string("Oh")));
	ismap m_total(m_even);
	m_total.insert(m_odd.begin(),m_odd.end());
	std::cout << BOLD << UNDERLINE << std::endl << "Testing member function find :" << END << std::endl;
	std::cout << "m_odd : ";
	for (ismap::const_iterator it = m_odd.begin(); it != m_odd.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(4) != m_odd.end()?m_odd.find(4)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(9) != m_odd.end()?m_odd.find(9)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(1) != m_odd.end()?m_odd.find(1)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(7) != m_odd.end()?m_odd.find(7)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(0) != m_odd.end()?m_odd.find(0)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(2) != m_odd.end()?m_odd.find(2)->first:-1))<< END << std::endl;
	std::cout << std::endl << "m_even :";for (ismap::const_iterator it = m_even.begin(); it != m_even.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(4) != m_even.end()?m_even.find(4)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(9) != m_even.end()?m_even.find(9)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(1) != m_even.end()?m_even.find(1)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(7) != m_even.end()?m_even.find(7)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(0) != m_even.end()?m_even.find(0)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(2) != m_even.end()?m_even.find(2)->first:-1))<< END << std::endl;
	std::cout << std::endl << "m_total : ";for (ismap::const_iterator it = m_total.begin(); it != m_total.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(4) != m_total.end()?m_total.find(4)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(9) != m_total.end()?m_total.find(9)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(1) != m_total.end()?m_total.find(1)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(7) != m_total.end()?m_total.find(7)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(0) != m_total.end()?m_total.find(0)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(2) != m_total.end()?m_total.find(2)->first:-1))<< END << std::endl;
}

void test_map_equal_range(){
	std::cout << BOLD << UNDERLINE << std::endl << "Testing member function equal range :" << END << std::endl;
	ismap m_odd;
	for (int i = 1; i < 20; i+=2)
		m_odd.insert(ispair(i,std::string("Hisse")));
	std::cout << "Testing with a Key value of 5 :" << std::endl;
	NAMESPACE::pair<ismap::iterator,ismap::iterator> p(m_odd.equal_range(5));
	std::cout << LIGHTYELLOW << "lower_bound" << END << " = " <<  LIGHTORANGE << p.first->first << LIGHTYELLOW << " upper_bound" << END << " = " <<  LIGHTORANGE << p.second->first << END << std::endl;
	std::cout << "Testing with a Key value of 4 :" << std::endl;
	NAMESPACE::pair<ismap::const_iterator,ismap::const_iterator> p2(m_odd.equal_range(4));
	std::cout << LIGHTYELLOW << "lower_bound" << END << " = " <<  LIGHTORANGE << p2.first->first << LIGHTYELLOW << " upper_bound" << END << " = " <<  LIGHTORANGE << p2.second->first << END << std::endl;
	std::cout << "Testing with a Key value of 6 :" << std::endl;
	NAMESPACE::pair<ismap::const_iterator,ismap::const_iterator> p3(m_odd.equal_range(6));
	std::cout << LIGHTYELLOW << "lower_bound" << END << " = " <<  LIGHTORANGE << p3.first->first << LIGHTYELLOW << " upper_bound" << END << " = " <<  LIGHTORANGE << p3.second->first << END << std::endl;
	std::cout << "Testing with a Key value of 11 :" << std::endl;
	NAMESPACE::pair<ismap::const_iterator,ismap::const_iterator> p4(m_odd.equal_range(11));
	std::cout << LIGHTYELLOW << "lower_bound" << END << " = " <<  LIGHTORANGE << p4.first->first << LIGHTYELLOW << " upper_bound" << END << " = " <<  LIGHTORANGE << p4.second->first << END << std::endl;
}

void test_map_key_comp(){
	std::cout << BOLD << UNDERLINE << "Testing member function key comp :" << END << std::endl;
	ismap m_lesser;
	NAMESPACE::map<int,std::string,std::greater<int> > m_greater;
	std::cout << "Testing with a std::less<int> as Comp Object :" << END << std::endl;
	if (m_lesser.key_comp()(3,4))
		std::cout << "3 is lesser than 4" << std::endl;
	else
		std::cout << "4 is greater than 3" << std::endl;
	std::cout << "Testing with a std::greater<int> as Comp Object :" << END << std::endl;
	if (m_greater.key_comp()(3,4))
		std::cout << "3 is lesser than 4" << std::endl;
	else
		std::cout << "4 is greater than 3" << std::endl;
}

void test_map_value_comp(){
	std::cout << std::endl << BOLD << UNDERLINE << "Testing member function value comp :" << END << std::endl;
	ismap m_lesser;
	NAMESPACE::map<double,double,std::greater<double> > m_greater;
	ispair p(4,"Bonjour");
	ispair p2(9,"Salut");
	ddpair d(10,3.15);
	ddpair d2(0.0000001,3.16);
	std::cout << "Testing with a std::less<int> as Comp Object :" << END << std::endl;
	if (m_lesser.value_comp()(p,p2))
		std::cout << "p is lesser than p2" << std::endl;
	else
		std::cout << "p2 is lesser than p" << std::endl;
	std::cout << "Testing with a std::greater<int> as Comp Object :" << END << std::endl;
	if (m_greater.value_comp()(d,d2))
		std::cout << "d is greater than d2" << std::endl;
	else
		std::cout << "d2 is greater than d" << std::endl;
}


void test_ft_swap_specialization(){
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ismap m;
	ismap m2;
	for (int i = 1; i < 20; i+=2)
		m2.insert(ispair(i,std::string("Hey")));
	ismap m3;
	for (int i = 0; i < 20; i+=2)
		m3.insert(ispair(i,std::string("Hey")));

	std::cout << BOLD << UNDERLINE << "Testing swap specialization" << END << std::endl;

	std::cout << "Swapping m2 and m3" << std::endl;
	std::cout << "Befrore m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	ft::swap(m2,m3);
	std::cout << "After m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "Swapping m3 and m" << std::endl;

	std::cout << "Befrore m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	ft::swap(m3,m);
	std::cout << "After m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;


	std::cout << "Swapping m and m2" << std::endl;
	std::cout << "Befrore m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "After m:" << std::endl;
	ft::swap(m,m2);
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
}

void test_equality_operators()
{
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	std::cout << BOLD << UNDERLINE << std::endl << "Testing equality operators" << END << std::endl;
	ismap m;
	ismap m2;
	for (int i = 0; i < 16; i+=2)
		m2.insert(ispair(i,std::string("Hey")));
	ismap m3;
	for (int i = 0; i < 20; i+=2)
		m3.insert(ispair(i,std::string("Oh")));
	ismap m4(m3);
	m.insert(ispair(291,std::string("Salut")));

	std::cout << "m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "m4:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m4.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m4.begin(); it != m4.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << std::endl;

	std::cout << "Comparing m2 with m3 :" << std::endl;
	print_operators("Map",m2,m3);
	std::cout << "Comparing m with m2 :" << std::endl;
	print_operators("Map",m,m2);
	std::cout << "Comparing m4 with m3 :" << std::endl;
	print_operators("Map",m4,m3);
}

