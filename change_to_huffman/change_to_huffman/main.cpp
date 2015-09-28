#include<iostream>
#include<string>
using namespace std;

struct vertex{
	int weight=0;//权重
	char name='\0';//叶节点代表的字母
	string code;
	int number=-1;//为节点起一个名字
	int left=-2;
	int right=-2;
	int parent=-3;
};
//完成code属性
void get_code(vertex*node, int num_of_vertex){
	for (int i = 0; i < num_of_vertex; i++){
		for (int j = 0; j < num_of_vertex; j++){
			if (node[j].left == node[i].number){
				node[i].code = "1";
			}
			if (node[j].right == node[i].number){
				node[i].code = "0";
			}
		}
	}
}
//编码（写错了）//已修改//还是错了
void coding(vertex *node, int num_of_vertex){
	get_code(node, num_of_vertex);
	for (int i = 0; i < num_of_vertex; i++){
		if (node[i].name != '\0'){
			int temp = i;
			loop:for (int j = 0; j < num_of_vertex; j++){
				if ((node[j].left == node[temp].number) || (node[j].right == node[temp].number)){
					node[i].code = node[j].code + node[i].code;
					temp = j;
					goto loop;
				}
			}
		}
	}
}
//返回有多少叶节点
int account(char *text){
	int length = 0;
	for (int i = 0; text[i] != '\0'; i++){
		length = i+1;
	}
	bool*p = new bool[length];
	int account=0;
	for (int i = 0; i < length; i++){
		p[i] = 0;
	}
	for (int i = 0; i < length; i++){
		if (p[i] == 0){
			p[i] = 1;
			account++;
			for (int j = i+1; j < length; j++){
				if (text[j] == text[i]){
					p[j] = 1;
				}
			}
		}
	}
	delete[]p;
	return account;
}
//传入一个节点数列，定义weight值、name值，number值。
void weight(char text[], vertex *node){
	int num_of_leaf = account(text);
	int length = 0;
	for (int i = 0; text[i] != '\0'; i++){
		length = i + 1;
	}
	bool *record = new bool[length];
	int count = 0;
	for (int i = 0; i < length; i++){
		record[i] = 0;
	}
	for (int i=0; i < length; i++){
		if (record[i] == 0){
			node[count].name = text[i];
			node[count].weight = 1;
			node[count].number = count;
			for (int j = i+1; j < length; j++){
				if ((record[j] == 0) && (text[j] == text[i])){
					node[count].weight += 1;
					record[j] = 1;
				}
			}
			count += 1;
			record[i] = 1;
		}
	}
	delete[]record;
}

void swap(vertex &v1, vertex &v2){
	vertex temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

void sort(vertex*node,int num){
	for (int i = 0; i < num; i++){
		for (int j = i + 1; j < num+1; j++){
			if (node[i].weight>node[j].weight){
				swap(node[i], node[j]);
			}
		}
	}
}

void set_son_and_parent(vertex &vfather, vertex &vleft_son, vertex &vright_son){
	vfather.weight = vleft_son.weight + vright_son.weight;
	vfather.left = vleft_son.number;
	vfather.right = vright_son.number;
	vleft_son.parent = vfather.number;
	vright_son.parent = vfather.number;
}

void swap_from_to(vertex*node, int limit){
	swap(node[0], node[limit]);
	for (int i = 1; i < limit; i++){
		swap(node[i], node[i + 1]);
	}
}
//确定每一个节点除编码外的所有值
void set_vertex(char text[],vertex *node){
	int num_of_leaf = account(text);
	int num_of_vertices = 2 * num_of_leaf + 1;
	int count = 0;
	weight(text, node);//此时前num_of_leaf个节点除了父节点属性都已确定了
	for (int i = num_of_leaf; i > 1; i--){
		sort(node, i-1);
		set_son_and_parent(node[num_of_leaf + count], node[0], node[1]);
		node[num_of_leaf + count].number = num_of_leaf + count;
		swap_from_to(node, num_of_leaf + count);
		count++;
	}
}

void print_weight(char text[],vertex*node){
	cout << "本段文字共有" << account(text) << "个字母。" << endl;
	for (int i = 0; node[i].name!='\0'; i++){
		cout << node[i].name << "出现了" << node[i].weight << "次。" << endl;
	}
}
//把所有的值都初始化为0
void set_a_vertex(vertex v){
	v.left = -1;
	v.right = -1;
	v.name = '\0';
	v.parent = -3;
	v.weight = 0;
}

void print_code(vertex *node,int limit){
	for (int i = 0; i < limit; i++){
		if (node[i].name != '\0'){
			cout << node[i].name << "的编码是" << node[i].code << endl;
		}
	}
}
//完成编码
void format(char text[]){
	int num_of_leaf = account(text);
	int num_of_vertex = 2 * num_of_leaf + 1;
	vertex *node = new vertex[num_of_vertex];
	for (int i = 0 ; i < num_of_vertex; i++){
		set_a_vertex(node[i]);
	}
	weight(text, node);
	print_weight(text, node);
	set_vertex(text, node);
	coding(node, num_of_vertex);
	print_code(node, num_of_vertex);
	node[0];
	node[1];
	node[2];
	node[3];
	node[4];
	node[5];
	node[6];
	node[7];
}

void main(){
	char text[100];
	cout << "输入字符：" << endl;
	cin >> text;
	format(text);
}