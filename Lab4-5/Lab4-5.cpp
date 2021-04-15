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
    temp->Prev = NULL;                   //Указываем, что изначально по следующему адресу пусто
    temp->Value = item;                         //Записываем значение в структуру

    if (Head != NULL)                    //Если список не пуст
    {
        temp->Next = Head;               //Указываем адрес на предыдущий элемент в соотв. поле
        Head->Prev = temp;               //Указываем адрес следующего за хвостом элемента
        Head = temp;                     //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->Next = NULL;               //Предыдущий элемент указывает в пустоту
        Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void myList::Print_list() {
    Node* temp = Tail;                   //Временный указатель на адрес последнего элемента
    cout << "List: ";
    temp = Head;                       //Временно указываем на адрес первого элемента
    while (temp != NULL)              //Пока не встретим пустое значение
    {
        cout << temp->Value << " ";        //Выводим каждое считанное значение на экран
        temp = temp->Next;             //Смена адреса на адрес следующего элемента
    }
    cout << "\n";
}

void myList::Search_item(int item) {
    Node* temp = Head;
    while (temp != NULL) {
        if (temp ->Value == item)
        {
            cout << "Found" << endl;
        }
        temp = temp->Next;
    }
}

void myList::Delete_item() {
    if ((Tail != NULL) && (Head != Tail)) {  //если список не пустой и не состоит из 1 элемента
        Node* temp = Tail;	                            
        Tail = Tail->Prev;	                                
        Tail->Next = NULL;	                                
        delete temp;	                                    
        cout << "Succsesfully deleted" << endl;
    }
    else
    {
        if ((Head == Tail) && (Head != NULL)) {  //Если всего 1 элемент
            Head->Next = NULL;
            Head = NULL;
            Tail = NULL;
            delete Head;
            delete Tail;
            cout << "Succsesfully deleted" << endl;
        }
        else
        {
            if (Head == NULL && Tail == NULL)  //Если список пустой
            {
                cout << "Error. List is empty" << endl;
            }
        }
    }
}
    
       
    


int main()
{
    system("CLS");
    myList lst;
    auto item = 0;
    cout << "Choose an option:" << endl<<endl;
    cout << "1. Add item to List" << endl;
    cout << "2. Remove last item from List" << endl;
    cout << "3. Search item in a List" << endl;
    cout << "4. Print List" << endl;
    cout << "5. Exit" << endl;
    cout << endl;
    auto a=-1;
    auto While = true;
    while (While) {
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "Enter a number to add:" << endl;
            cin >> item;
            lst.Add_item(item);
            break;
        case 2:
            lst.Delete_item();
            break;
        case 3:
            cout << "Enter a number to find:" << endl;
            cin >> item;
            lst.Search_item(item);
            break;
        case 4:
            lst.Print_list();
            break;
        case 5:
            While = false;

            break;
        default:
            cout << "Not an option" << endl;;
            While = false;
   
            break;
        }
    }
      
   
    //TODO сделать ввод в список из файла
   

}

