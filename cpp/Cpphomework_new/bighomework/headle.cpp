/**
 * 界面功能的实现
 * @author zyd
 * @date 2022/4/17
 *
 **/

#include "polynomial.cpp"

using namespace std;

/*int main()
{
    Poly *l;
    l = l->CreateP();
    showP(l);
    BubbleSort(l);
    showP(l);

    // Poly *l2 = l2->CreateP();
    // BubbleSort(l2);
    // showP(l2);
    // Poly* l3 = *l + *l2;
    // showP(l3);
    // Poly* l4 = *l - *l2;
    // showP(l4);

    cout << Count(l, 2);
    return 0;
}
//以上均是测试时的用例用完请注释
*/

Poly *l1, *l2;
int main()
{
    cout << "##############################" << endl;
    cout << "   欢迎使用该多项式计算器" << endl;
    cout << "       1.加入新的多项式" << endl;
    cout << "       2.展示输入的多项式" << endl;
    cout << "       3.计算多项式加法" << endl;
    cout << "       4.计算多项式减法" << endl;
    cout << "       5.输入值计算多项式" << endl;
    cout << "       6.结束" << endl;

    int choose;
    while (1)
    {
        cout << "请选择需要的服务: (输入数字例: 1)" << endl;
        // cout << cin.good();
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            l1 = l1->CreateP();
            l2 = l2->CreateP();
            BubbleSort(l1);
            BubbleSort(l2);
            showP(l1);
            showP(l2);
            break;
        case 2:
            showP(l1);
            showP(l2);
            break;
        case 3:
            cout << "相加结果如下: " << endl;
            showP(*l1 + *l2);
            break;
        case 4:
            cout << "相互减的结果如下: " << endl;
            showP(*l1 - *l2);
            showP(*l2 - *l1);
            break;
        case 5:
            int n;
            cout << "请输入x的值" << endl;
            cin >> n;
            cout << "第一个多项式的值: " << endl;
            cout << Count(l1, n) << endl;
            cout << "第二个多项式的值: " << endl;
            cout << Count(l2, n) << endl;
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "请输入包含在内的数字! " << endl;
            break;
        }
    }

    return 0;
}