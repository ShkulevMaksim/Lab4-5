#include <iostream>
#include <fstream>

using namespace std;


struct node {
	int value;
	node* next, * prev;
};

class my_list
{
    node* head_, * tail_;                 //Указатели на адреса начала списка и его конца
public:
    my_list() :head_(nullptr), tail_(nullptr) {}
    ~my_list();                           //Прототип деструктора
    void print_list() const;                       //Прототип функции отображения списка на экране
    void add_item(int item);
    void search_item(int item) const;
    void delete_item();
    
};

my_list::~my_list()                           //Деструктор
{
    while (head_)                       //Пока по адресу на начало списка что-то есть
    {
        tail_ = head_->next;             //Резервная копия адреса следующего звена списка
        delete head_;                   //Очистка памяти от первого звена
        head_ = tail_;                   //Смена адреса начала на адрес следующего элемента
    }
}

void my_list::add_item(const int item){
	const auto temp = new node;               //Выделение памяти под новый элемент структуры
    temp->prev = nullptr;                   //Указываем, что изначально по следующему адресу пусто
    temp->value = item;                         //Записываем значение в структуру

    if (head_ != nullptr)                    //Если список не пуст
    {
        temp->next = head_;               //Указываем адрес на предыдущий элемент в соотв. поле
        head_->prev = temp;               //Указываем адрес следующего за хвостом элемента
        head_ = temp;                     //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->next = nullptr;               //Предыдущий элемент указывает в пустоту
        head_ = tail_ = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void my_list::print_list() const
{
	node* temp = tail_;                   //Временный указатель на адрес последнего элемента
    cout << "List: ";
    temp = head_;                       //Временно указываем на адрес первого элемента
    while (temp != nullptr)              //Пока не встретим пустое значение
    {
        cout << temp->value << " ";        //Выводим каждое считанное значение на экран
        temp = temp->next;             //Смена адреса на адрес следующего элемента
    }
    cout << "\n";
}

void my_list::search_item(const int item) const
{
    node* temp = head_;
    while (temp != nullptr) {
        if (temp ->value == item)
        {
            cout << "Found" << endl;
        }
        temp = temp->next;
    }
}

void my_list::delete_item() {
    if ((tail_ != nullptr) && (head_ != tail_)) {  //если список не пустой и не состоит из 1 элемента
        node* temp = tail_;	                            
        tail_ = tail_->prev;	                                
        tail_->next = nullptr;	                                
        delete temp;	                                    
        cout << "Successfully deleted" << endl;
    }
    else
    {
        if ((head_ == tail_) && (head_ != nullptr)) {  //Если всего 1 элемент
            head_->next = nullptr;
            head_ = nullptr;
            tail_ = nullptr;
            delete head_;
            delete tail_;
            cout << "Successfully deleted" << endl;
        }
        else
        {
            if (head_ == nullptr && tail_ == nullptr)  //Если список пустой
            {
                cout << "Error. List is empty" << endl;
            }
        }
    }
}

void generate_file(const string& filename)
{
    std::ofstream my_file(filename);
    srand(time(nullptr));
    auto num = 0;
    cout << "Enter number of lines: " << endl;
    cin >> num;

    for (auto i = 0; i < num; i++)
    {
        for (auto j = 0; j < 5; j++)
        {
            my_file << static_cast<int>(rand()) << "\t";
        }
        my_file << std::endl;
    }
    my_file.close();
}

void fill_list(my_list &lst, const string filename)
{
	  int temp;
    std::ifstream my_file;
    my_file.open(filename);
    while (my_file >> temp) {
        (&lst)->add_item(temp);
    }
    my_file.close();
    

}



int main()
{
    system("CLS");
    my_list lst;
    const string filename = "C:/Users/mksh2/source/repos/Lab4-5/input.txt";
	generate_file(filename);
    fill_list(lst, filename);
    lst.print_list();
    

    
	
    cout << "Choose an option:" << endl<<endl;
    cout << "1. Add item to List" << endl;
    cout << "2. Remove last item from List" << endl;
    cout << "3. Search item in a List" << endl;
    cout << "4. Print List" << endl;
    cout << "5. Exit" << endl;
    cout << endl;
    auto a=-1;
    auto While = true;
	auto item = 0;
    while (While) {
        cin >> a;
        switch (a)
        {
	        

        case 1:
            cout << "Enter a number to add:" << endl;
            cin >> item;
            lst.add_item(item);
            break;
        case 2:
            lst.delete_item();
            break;
        case 3:
            cout << "Enter a number to find:" << endl;
            cin >> item;
            lst.search_item(item);
            break;
        case 4:
            lst.print_list();
            break;
        case 5:
            While = false;

            break;
        default:
            cout << "Not an option" << endl;
            While = false;
   
            break;
        }
    }
      
}

