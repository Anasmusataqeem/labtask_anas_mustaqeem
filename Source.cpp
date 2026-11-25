#include <iostream>

template <typename T>
class set
{
    struct node
    {
        T val;
        node* left, * right, * parent;

        node()
        {
            left = right = parent = nullptr;
        }
    };

    node* head;

public:

    set()
    {
        head = new node;
        head->parent = head->left = head->right = head;
    }

    void insert(const T& val)
    {
        node* temp;
        temp = new node;
        temp->val = val;
        temp->left = temp->right = head;

        if (head->parent == head)
        {
            head->parent = temp;
            temp->parent = head;
            head->left = head->right = temp;
            return;
        }
        else
        {
            node* ptr;
            ptr = head->parent;

            while (ptr != head)
            {
                if (ptr->val > temp->val)
                {
                    if (ptr->left == head)
                    {
                        ptr->left = temp;
                        temp->parent = ptr;
                        break;
                    }
                    else
                    {
                        ptr = ptr->left;
                    }
                }
                else
                {
                    if (ptr->right == head)
                    {
                        ptr->right = temp;
                        temp->parent = ptr;
                        break;
                    }
                    else
                    {
                        ptr = ptr->right;
                    }
                }
            }

            if (temp->val < head->left->val)
            {
                head->left = temp;
            }

            if (temp->val > head->right->val)
            {
                head->right = temp;
            }
        }
    }
    bool empty() const
    {
        if (head->parent == head)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    set<int> s;

    s.insert(5);
    s.insert(3);
    s.insert(7);
    s.insert(4);
    s.insert(2);
    s.insert(9);

    std::cout<<s.empty();
    return 0;
}