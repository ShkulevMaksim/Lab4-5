#include <iostream>

using namespace std;


struct Node {
	int Value;
	Node* Next, * Prev;
};

class myList
{
    Node* Head, * Tail;                 //Указатели на адреса начала списка и его конца
public:
    myList() :Head(NULL), Tail(NULL) {};    //Инициализируем адреса как пустые
    ~myList();                           //Прототип деструктора
    void Print_list();                       //Прототип функции отображения списка на экране
    void Add_item(int item);
    void Search_item(int item);
    void Delete_item();
};

myList::~myList()                           //Деструктор
{
    while (Head)                       //Пока по адресу на начало списка что-то есть
    {
        Tail = Head->Next;             //Резервная копия адреса следующего звена списка
        delete Head;                   //Очистка памяти от первого звена
        Head = Tail;                   //Смена адреса начала на адрес следующего элемента
    }
}

void myList::Add_item(int item){
    Node* temp = new Node;               //Выделение памяти под новый элемент структуры
    temp->Next = NULL;                   //Указываем, что изначально по следующему адресу пусто
    temp->Value = item;                         //Записываем значение в структуру

    if (Head != NULL)                    //Если список не пуст
    {
        temp->Prev = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
        Tail->Next = temp;               //Указываем адрес следующего за хвостом элемента
        Tail = temp;                     //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->Prev = NULL;               //Предыдущий элемент указывает в пустоту
        Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void myList::Print_list() {
    Node* temp = Tail;                   //Временный указатель на адрес последнего элемента

    temp = Head;                       //Временно указываем на адрес первого элемента
    while (temp != NULL)              //Пока не встретим пустое значение
    {
        cout << temp->Value << " ";        //Выводим каждое считанное значение на экран
        temp = temp->Next;             //Смена адреса на адрес следующего элемента
    }
    cout << "\n";
}

void myList::Search_item(int item) {
    //TODO
}

void myList::Delete_item() {
    //TODO
}

int main()
{
    system("CLS");
    myList lst;
    auto item = 0;
    cout << "Choose an option:" << endl<<endl;
    cout << "1. Add item to List" << endl;
    cout << "2. Remove item from List" << endl;
    cout << "3. Search item in a List" << endl;
    cout << "4. Print List" << endl;
    cout << "5. Exit" << endl;
    cout << endl;
    auto a=-1;
    bool While = true;
    while (While) {
        cin >> a;
        switch (a)
        {
        case 1:
            
            lst.Add_item(item);
            break;
        case 2:
            lst.Delete_item();
            break;
        case 3:
            lst.Search_item(item);
            break;
        case 4:
            lst.Print_list();
            break;
        case 5:
            While = false;

            break;
        default:
            cout << "error\n";
            While = false;
   
            break;
        }
    }
      
   
    //TODO сделать ввод в список из файла
   

}

