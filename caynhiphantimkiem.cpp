

#include<iostream>
using namespace std;

// nh?p v�o c�y nh? ph�n t�m ki?m c�c s? nguy�n

// khai b�o c?u tr�c 1 c�i node trong c�y nh? ph�n t�m ki?m
struct node
{
	int data; // d? li?u ch?a trong 1 c�i node
	struct node *pLeft; // con tr? li�n k?t v?i c�i node b�n tr�i <=> c�y con tr�i
	struct node *pRight; // con tr? li�n k?t v?i c�i node b�n ph?i <=> c�y con ph?i
};
typedef struct node NODE;
typedef NODE* TREE;

// h�m kh?i t?o c�y nh? ph�n t�m ki?m
void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

// h�m th�m 1 c�i ph?n t? v�o c�y
void ThemNodeVaoCay(TREE &t, int x)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		// n?u ph?n t? th�m v�o m� nh? hon n�t g?c th� s? duy?t qua b�n tr�i
		if (x < t->data)
		{
			ThemNodeVaoCay(t->pLeft, x);
		}
		else if (x > t->data)
		{
			ThemNodeVaoCay(t->pRight, x);
		}
	}
}

// h�m xu?t ph?n t? trong c�y nh? ph�n t�m ki?m
void NLR(TREE t)
{
	if (t != NULL)
	{
		// x? l�
		cout << t->data << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// n?u node c� t?n t?i trong c�y th� tr? v? c�i node d� - c�n kh�ng t?n t?i th� tr? v? NULL
NODE* TimKiem(TREE t, int x)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// n?u ph?n t? c?n t�m ki?m m� nh? hon node g?c th� duy?t(d? quy) sang b�n tr�i d? t�m
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data) // duy?t sang b�n ph?i
		{
			TimKiem(t->pRight, x);
		}
		else // <=> t->data == x
		{
			return t; // tr? v? node c?n t�m ki?m
		}
	}

}


// xu?t c�c node c� 2 con
void Node_Co_2_Con(TREE t)
{
	if (t != NULL)
	{
		// x? l�
		if (t->pLeft != NULL && t->pRight != NULL) // con tr�i v� con ph?i c� t?n t?i ph?n t?
		{
			cout << t->data << "  ";
		}
		Node_Co_2_Con(t->pLeft); // duy?t sang c�y con tr�i c?a node hi?n t?i
		Node_Co_2_Con(t->pRight); // duy?t sang c�y con ph?i c?a node hi?n t?i
	}
}
// xu?t c�c node c� 1 con
void Node_Co_1_Con(TREE t)
{
	if (t != NULL)
	{
		// x? l�
		if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
		{
			cout << t->data << "  ";
		}
		Node_Co_1_Con(t->pLeft); // duy?t sang c�y con tr�i c?a node hi?n t?i
		Node_Co_1_Con(t->pRight); // duy?t sang c�y con ph?i c?a node hi?n t?i
	}
}

// xu?t c�c node l�
void Node_La(TREE t)
{
	if (t != NULL)
	{
		// x? l�
		if (t->pLeft == NULL && t->pRight == NULL)
		{
			cout << t->data << "  ";
		}
		Node_La(t->pLeft); // duy?t sang c�y con tr�i c?a node hi?n t?i
		Node_La(t->pRight); // duy?t sang c�y con ph?i c?a node hi?n t?i
	}
}
// C�CH 1: T�M MAX
//int MAX = INT_MIN; // g�n cho bi?n MAX l� gi� tr? nh? nh?t c?a ki?u integer
//// h�m t�m ph?n t? l?n nh?t trong c�y
//void TimMax(TREE t)
//{
//	if (t != NULL)
//	{
//		// x? l�
//		if (MAX < t->data)
//		{
//			MAX = t->data; // c?p nh?t l?i gi� tr? cho bi?n MAX
//		}
//		TimMax(t->pLeft);
//		TimMax(t->pRight);
//	}
//}

// C�CH 2: T�M MAX1
int TimMax(TREE t)
{
	//// n?u node cha m� kh�ng t?n t?i c�y con tr�i v� c�y con ph?i
	//if (t->pLeft == NULL && t->pRight == NULL)
	//{
	//	return t->data;
	//}
	//int max = t->data; // g�n gi� tr? bi?n max ch�nh l� data c?a node cha 
	//// n?u node cha c� t?n t?i c�y con tr�i
	//if (t->pLeft != NULL)
	//{
	//	int left = TimMax(t->pLeft); // left l� bi?n s? gi? gi� tr? c?a c�i node ngo�i c�ng nh?t b�n tr�i c?a node cha
	//	if (max < left)
	//	{
	//		max = left;
	//	}
	//}
	//// n?u node cha c� t?n t?i c�y con ph?i
	//if (t->pRight != NULL)
	//{
	//	int right = TimMax(t->pRight); // right l� bi?n s? gi? gi� tr? c?a c�i node ngo�i c�ng nh?t b�n ph?i c?a node cha
	//	if (max < right)
	//	{
	//		max = right;
	//	}
	//}
	//return max; // tr? v? gi� tr? l?n nh?t c?a c�y nh? ph�n t�m ki?m

	// C�CH T?I UU NH?T
	// n?u node cha m� kh�ng t?n c�y con ph?i - th� node cha n�y ch�nh l� node ngo�i c�ng nh?t c?a c�y con ph?i - cung ch�nh l� node c� gi� tr? l?n nh?t
	if (t->pRight == NULL)
	{
		return t->data;
	}
	return TimMax(t->pRight); // duy?t d?n node cu?i c�ng nh?t b�n c�y con ph?i ==> d? t�m gi� tr? l?n nh?t
}


// h�m t�m node th? m?ng Y
// T�m node PH?I NH?T c?a c�y con TR�I
void NodeTheMang(TREE &X, TREE &Y)
{
	if (Y->pRight != NULL)
	{
		NodeTheMang(X, Y->pRight);
	}
	else
	{
		X->data = Y->data;
		X = Y;
		Y = Y->pLeft;
	}
}

// h�m t�m node th? m?ng
void DiTimNodeTheMang(TREE &X, TREE &Y) // NODE Y l� node th? m?ng cho node c?n x�a - node n�y s? d?m nh?n nhi?m v? t�m ra node tr�i nh?t(T�M NODE TR�I NH?T C�Y CON PH?I) ho?c ph?i nh?t(T�M NODE PH?I NH?T C?A C�Y CON TR�I)
{
	// C�CH 1: T�M NODE TR�I NH?T C?A C�Y CON PH?I
	// duy?t sang b�n tr�i nh?t
	if (Y->pLeft != NULL)
	{
		DiTimNodeTheMang(X, Y->pLeft);// t�m ra node tr�i nh?t ?
	}
	else // t�m ra du?c node tr�i nh?t r?i nek..
	{
		X->data = Y->data; // c?p nh?t c�i data c?a node c?n x�a ch�nh l� data c?a node th? m?ng
		X = Y; // cho node X(l� node m� ch�ng ta s? di x�a sau n�y) tr? d?n node th? m?ng ==> ra kh?i h�m th� ta s? x�a node X
		Y = Y->pRight; // b?n ch?t ch? n�y ch�nh l� c?p nh?t l?i m?i li�n k?t cho node cha c?a node th? m?ng(m� ch�ng ta s? x�a) v?i node con c?a node th? m?ng	
	}

	//// C�CH 2: T�M NODE PH?I NH?T C?A C�Y CON TR�I
	//// duy?t sang b�n ph?i
	//if (Y->pRight != NULL)
	//{
	//	DiTimNodeTheMang(X, Y->pRight);// t�m ra node ph?i nh?t ?
	//}
	//else // t�m ra du?c node ph?i nh?t r?i nek..
	//{
	//	X->data = Y->data; // c?p nh?t c�i data c?a node c?n x�a ch�nh l� data c?a node th? m?ng
	//	X = Y; // cho node X(l� node m� ch�ng ta s? di x�a sau n�y) tr? d?n node th? m?ng ==> ra kh?i h�m th� ta s? x�a node X
	//	Y = Y->pLeft; // b?n ch?t ch? n�y ch�nh l� c?p nh?t l?i m?i li�n k?t cho node cha c?a node th? m?ng(m� ch�ng ta s? x�a) v?i node con c?a node th? m?ng	
	//}
}

// h�m x�a 1 c�i node b?t k� trong c�y nh? ph�n t�m ki?m
void XoaNode(TREE &t, int data) // data ch�nh l� gi� tr? c?a c�i node c?n x�a
{
	// n?u nhu c�y dang r?ng
	if (t == NULL)
	{
		return; // k?t th�c h�m
	}
	else
	{
		// n?u nhu data nh? hon node g?c
		if (data < t->data)
		{
			XoaNode(t->pLeft, data); // duy?t sang nh�nh tr�i c?a c�y 
		}
		else if (data > t->data)
		{
			XoaNode(t->pRight, data); // duy?t sang nh�nh ph?i c?a c�y 
		}
		else // data == t->data - d� t�m ra c�i node c?n x�a
		{
			NODE *X = t; // node X l� node th? m?ng - t� n?a ch�ng ta s? x�a n�
			// n?u nhu nh�nh tr�i b?ng NULL <=> d�y l� c�y c� 1 con ch�nh l� con ph?i
			if (t->pLeft == NULL)
			{
				// duy?t sang ph?i c?a c�i node c?n x�a d? c?p nh?t m?i li�n k?t gi?a node 
				// cha c?a node c?n x�a v?i node con c?a node c?n x�a
				t = t->pRight; 
			}
			else if (t->pRight == NULL)
			{
				// duy?t sang tr�i c?a c�i node c?n x�a d? c?p nh?t m?i li�n k?t gi?a node 
				// cha c?a node c?n x�a v?i node con c?a node c?n x�a
				t = t->pLeft;
			}
			else // node c?n x�a l� node c� 2 con
			{
				// C�CH 1: T�m node tr�i nh?t c?a c�y con ph?i(c�y con ph?i c?a c�i node c?n x�a)
				DiTimNodeTheMang(X, t->pRight);
				// C�CH 2: T�m node ph?i nh?t c?a c�y con tr�i(c�y con tr�i c?a c�i node c?n x�a)
				//DiTimNodeTheMang(X, t->pLeft);
			}
			delete X; // x�a node c?n x�a
		}
	}
}


// h�m nh?p c�y nh? ph�n t�m ki?m
void Menu(TREE &t)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============ MENU ============";
		cout << "\n1. Nhap phan tu";
		cout << "\n2. Duyet cay";
		cout << "\n3. Tim kiem phan tu trong cay";
		cout << "\n4. Node co 2 con";
		cout << "\n5. Node co 1 con";
		cout << "\n6. Node la";
		cout << "\n7. Tim Max";
		cout << "\n8. Xoa";
		cout << "\n0. Thoat";
		cout << "\n\n\t\t =============  END  =============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t CAY NHI PHAN TIM KIEM\n";
			NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap phan tu can tim kiem: ";
			cin >> x;
			NODE *p = TimKiem(t, x);
			if (p == NULL)
			{
				cout << "\nPhan tu " << x << " khong ton tai trong cay";
			}
			else
			{
				cout << "\nPhan tu " << x << " co ton tai trong cay";
			}
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\t NODE CO 2 CON: ";
			Node_Co_2_Con(t);
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n\t NODE CO 1 CON: ";
			Node_Co_1_Con(t);
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n\t NODE LA: ";
			Node_La(t);
			system("pause");
		}
		else if (luachon == 7)
		{
			// C�CH 1:
			/*TimMax(t);
			cout << "\nMAX: " << MAX;*/

			// C�CH 2:
			cout << "\nMAX: " << TimMax(t);
			system("pause");
		}
		else if (luachon == 8)
		{
			int x;
			cout << "\nNhap gia tri can xoa: ";
			cin >> x;
			XoaNode(t, x);
		}
		else
		{
			break;
		}
	}
}


int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}
