#include "basis.h"
#include "func.h"
#include "etrdef.h"
char arr1[1000][1000] = { 0 };

struct username_type
{
    char name_arr[20];
    int user_type;
}arr2[1000]={0};


void menu_aams()
{
    menu_aams_display_1();


    int minput =0;
    cin>>minput;
    if(minput == 0 )
    {
        menu_aams_display_2();

        return ;
    }
    else if(minput==1)
    {
        string username="test";
        string password ="test";
        cout<<"********************************"<<endl;
        cout<<"please cin your count message"<<endl;
        cout<<"enter your username "<<endl;
        cin>>username;
        cout<<"********************************"<<endl;

        secgetpasseord(password);
        // cout<<"realpass:"<<password;//Test kink good
        //system("pause");
        cout<<endl;


        if( mysql_login(username, password) )

        {
            // printf("test.");//test point
            // system("pause");
            int swinum =getwhichmenu(username);
            // cout<<"swinum :"<<swinum;//test point
            // system("pause");
            switch (swinum)//��ʱmysql��������,����˵������ظ�����,�ʲ�������
            {
                case 1:menu_root();break;
                case 2:menu_student(username);break;
                case 3:menu_teacher(username);break;
                default : printf("Program error");break;
            }
        }
        else
        {
            menu_aams_display_3();
            main();

        }

    }
    else
    {
        system("cls");

        cout<<"***  error input         *******"<<endl;
        cout<<"***  please input again  *******"<<endl;

        menu_aams();
    }
}



int getwhichmenu(string testname)
{
    int usernum ;
    usernum = usermessget() + 1;//user number
    getstruct(usernum);
    int i = 0;
    for(;i<=usernum;i++)
    {
        if(testname == arr2[i].name_arr)
        {
            break;
        }
    }
    // cout<<"name"<<arr2[i].name_arr<<endl<<"type:"<<arr2[i].user_type<<endl;//test point
    return arr2[i].user_type;

}



void menu_root() {
    system("cls");
    cout << "Hello ";
    cout << "Welecome to root menu!!!"
         << endl;
    system("pause");
    system("cls");
    while (1) {
        int stuop;
        cout << "��ѡ���ܣ�1��������ʦ��Ϣ ��2��ɾ����ʦ��Ϣ  ��3������ѧ����Ϣ   "<<endl<<"\t"<<"  "<<"��4��ɾ��ѧ����Ϣ  (5)Ϊ��ʦ���ſγ� (6)�˳���¼ (7)�˳�ϵͳ" << endl;
        cout << "������ֵ :> ";
        cin >> stuop;
        switch (stuop) {
            case 1: {
                addTeacher(mysql);
                break;
            }
            case 2: {
                deleteTeacher(mysql);
                break;
            }
            case 3:{
                addStudent( mysql);
                break;
            }
            case 4:{
                deleteStudent(mysql);
                break;
            }
            case 5:{
                assignCourse(mysql);
                break;
            }
            case 6:{
                mysql_close(&mysql);
                system("cls");
                main();
                break;
            }
            case 7:{
                system("cls");
                cout<<"********************************"<<endl<<endl;
                cout<<"Successfully exited the system"<<endl<<endl;
                cout<<"********************************"<<endl<<endl;

                system("pause");
                exit(0);
            }
        }
    }
}
void menu_student(const string& username)
{
    system("cls");
    cout<<"Hello student "<<username<<endl;
    cout<<"Welecome to student menu!!!"<<endl;
    system("pause");
    system("cls");
    while(1) {
        int stuop;
        cout << "��ѡ���ܣ�1���鿴������Ϣ�Լ���ѧ������ѡ�γ�  "<<endl<<"\t"<<"  "<<"��2���鿴��ѧ�����пγ�   (3)�鿴��İ༶��Ϣ ��4��ѡ��  ��5���˿�  "
             << endl<<"\t"<<"   "<<"(6) �˳���¼ " <<" (7) �˳�ϵͳ"<<endl;
        cout << "������ֵ :> ";
        cin >> stuop;
        switch (stuop) {
            case 1: {
                showstu(mysql,username);
                break;
            }
            case 2: {
                showcourse(mysql,username);
                break;
            }
            case 4:{
                selectclass( mysql, username);
                break;
            }
            case 5:{
                dropclass(mysql,username);
                break;
            }
            case 6:{
                mysql_close(&mysql);
                system("cls");
                main();
                break;
            }
            case 7:{
                system("cls");
                cout<<"********************************"<<endl<<endl;
                cout<<"Successfully exited the system"<<endl<<endl;
                cout<<"********************************"<<endl<<endl;

                system("pause");
                exit(0);
            }
            case 3:{
                showClassmates(mysql, username);
                break;
            }

        }
    }

}
void menu_teacher(const string& username)
{
    system("cls");
    cout<<"Hello teacher "<<username<<endl;
    cout<<"Welecome to teacher menu!!!"<<endl;
    system("pause");
    system("cls");
    while(1) {
        int stuop;
        cout << "��ѡ���ܣ�1���鿴������Ϣ  ��2���鿴��ѧ�������̵Ŀγ���Ϣ�Լ���ѡ��ε�ѧ����Ϣ "<<endl<<"\t"<<" "<<" ��3��������Ŀγ�ѡ��ѧ����Ϣ��4��ɾ�������Ŀγ�ѡ��ѧ����Ϣ  (5) �޸�ѧ���ɼ�  "<<endl<<"\t"<<"   "<<"(6) �˳���¼ (7) �˳�ϵͳ " << endl;
        cout << "������ֵ :> ";
        cin >> stuop;
        switch (stuop) {
            case 1: {
                showtea(mysql,username);
                break;
            }
            case 2:{
                showSelectedstu(mysql, username);
                break;
            }
            case 3:{
                addstu( mysql, username);
                break;
            }
            case 4:{
                deletestu(mysql, username);
                break;
            }
            case 5:{
                updateGrade(mysql, username);
                break;
            }
            case 6:{
                mysql_close(&mysql);
                system("cls");
                main();
                break;
            }
            case 7:{
                system("cls");
                cout<<"********************************"<<endl<<endl;
                cout<<"Successfully exited the system"<<endl<<endl;
                cout<<"********************************"<<endl<<endl;

                system("pause");
                exit(0);
            }
        }
    }
}


//another func
void getstruct(int num)
{
    int i = 0;
    for (; i < num; i++)
    {
        sscanf(arr1[i], "%s %d", arr2[i].name_arr, &arr2[i].user_type);
    }

}
int usermessget()
{
    int k ;
    FILE* fp = fopen("user.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return 4;
    }

    {
        int i = 0;
        int j = 0;
        {
            char ch;
            while ((ch = (char)fgetc(fp)) != EOF)
            {
                if (ch == '\n')
                {
                    arr1[i][j] = '\0';
                    i++;
                    j = 0;
                }
                else
                {
                    arr1[i][j] = ch;
                    j++;
                }

            }
            arr1[i][j] = '\0';
        }
        k = i;
        //test
        //for (int m = 0; m <= k; m++)
        //{
        //    printf("%s\n", arr1[m]);
        //}
    }
    fclose(fp);
    return k;//�??�??-1
}

void menu_aams_display_1()
{

    cout<<"You are using the academic management system!!!"<<endl;
    cout<<"********************************"<<endl;
    cout<<"********** 1  :  login   *******"<<endl;
    cout<<"********** 0  :   exit   *******"<<endl;
    cout<<"********************************"<<endl;
    cout<<" 1 / 0 ->";
}
void menu_aams_display_2()
{
    system("cls");
    cout<<"********************************"<<endl;
    cout<<" AAMS System has closed!!!"<<endl;
    cout<<"********************************"<<endl;
    system("pause");
}
void menu_aams_display_3()
{
    cout<<"********************************"<<endl;
    cout<<" Account or password error!!!"<<endl;
    cout<<"********************************"<<endl;
}


void showstu(MYSQL &mysql, std::string username) {
    setCharset(mysql);
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"); // ��ֹ������������������

    // ������ѯ���
    std::string query = "SELECT stu.*, sc.* FROM stu JOIN sc ON stu.sno = sc.sno WHERE stu.sno = '" + username + "'";

    // ִ�в�ѯ
    if (mysql_query(&mysql, query.c_str())) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        mysql_close(&mysql);
        return;
    }

    // ��ȡ��ѯ���
    res = mysql_use_result(&mysql);
    int num = mysql_num_fields(res);

    // �õ������е����֣��������
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(15) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // ��������������е���
    while ((row = mysql_fetch_row(res)) != NULL) {
        // ����ǰ���е�ÿһ����Ϣ����
        for (int i = 0; i < num; ++i) {
            std::cout << std::left << std::setw(15) << (row[i] ? row[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
    }

    // �ͷŽ����
    mysql_free_result(res);
}

void showcourse(MYSQL &mysql, std::string username) {
    setCharset(mysql);
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"); // ��ֹ������������������

    // ������ѯ���
    std::string query = "SELECT course.* FROM course";

    // ִ�в�ѯ
    if (mysql_query(&mysql, query.c_str())) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        mysql_close(&mysql);
        return;
    }

    // ��ȡ��ѯ���
    res = mysql_use_result(&mysql);
    int num = mysql_num_fields(res);

    // �õ������е����֣��������
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // ��ӡ�ָ���
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << std::string(20, '-') << "\t";
    }
    std::cout << std::endl;

    // ��������������е���
    while ((row = mysql_fetch_row(res)) != NULL) {
        // ����ǰ���е�ÿһ����Ϣ����
        for (int i = 0; i < num; ++i) {
            std::cout << std::left << std::setw(20) << (row[i] ? row[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
    }

    // �ͷŽ����
    mysql_free_result(res);
}

void selectclass(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    int course_con;
    setCharset(mysql);
    std::cout << "��������Ҫѡ�޵Ŀγ̺�: ";
    std::cin >> course_con;

    int sno = std::stoi(username); // ���û�����ѧ��ѧ�ţ�ת��Ϊ int

    // �����������
    //sprintf(sql, "INSERT INTO sc VALUES(%d, %d, NULL)", sno, course_con);
    sprintf(sql, "CALL stu_getmessage(%d, %d)", sno, course_con);

    // ִ�в�ѯ
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    std::cout << "����ɹ�" << std::endl;
    std::cout << "��Ŀα����£�" << std::endl;

    showSelectedCourses(mysql, username); // ������ʾ�γ̱�ĺ���
}

void dropclass(MYSQL &mysql, string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    int course_con;
    setCharset(mysql);
    cout << "��������Ҫ��ѡ�Ŀγ̺�: ";
    cin >> course_con;

    int sno = stoi(username); // ���û�����ѧ��ѧ�ţ�ת��Ϊ int

    // ����ɾ�����
    //sprintf(sql, "DELETE FROM sc WHERE sno = %d AND cno = %d", sno, course_con);
    sprintf(sql, "CALL stu_giveupsc(%d, %d)", sno, course_con);

    // ִ�в�ѯ
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    cout << "�˿γɹ�" << endl;
    cout<<"��Ŀα����£�"<<endl;

    showSelectedCourses(mysql, username); // �������ʾѧ����Ϣ�ĺ������������������
}

void showSelectedCourses(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    setCharset(mysql);
    int sno = std::stoi(username); // ���û�����ѧ��ѧ�ţ�ת��Ϊ int

    // ������ѯ��䣬ʹ����ͼ�򻯲�ѯ
    sprintf(sql,
            "SELECT sno, sname, cno, cname, grade FROM View_StudentCourses WHERE sno = %d",
            sno);

    // ִ�в�ѯ
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ��ȡ��ѯ���
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    int num = mysql_num_fields(res);

    // �������
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // ��ӡ�ָ���
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << std::string(20, '-') << "\t";
    }
    std::cout << std::endl;

    // ��������������е���
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < num; ++i) {
            if (row[i] == NULL) {
                std::cout << std::left << std::setw(20) << "δ����" << "\t";
            } else {
                std::cout << std::left << std::setw(20) << row[i] << "\t";
            }
        }
        std::cout << std::endl;
    }

    // �ͷŽ����
    mysql_free_result(res);
}


void showtea(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    setCharset(mysql);
    int tno = std::stoi(username); // ���û�������ʦ�ţ�ת��Ϊ int

    // ������ѯ���
    sprintf(sql,
            "SELECT * "
            "FROM teacher "
            "WHERE tno = %d",
            tno);

    // ִ�в�ѯ
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ��ȡ��ѯ���
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    int num = mysql_num_fields(res);

    // �������
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // ��ӡ�ָ���
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << std::string(20, '-') << "\t";
    }
    std::cout << std::endl;

    // ��������������е���
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < num; ++i) {
            if (row[i] == NULL) {
                std::cout << std::left << std::setw(20) << "NULL" << "\t";
            } else {
                std::cout << std::left << std::setw(20) << row[i] << "\t";
            }
        }
        std::cout << std::endl;
    }

    // �ͷŽ����
    mysql_free_result(res);
}


void deletestu(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[2000];
    int tno = std::stoi(username); // ���û�������ʦ�ţ�ת��Ϊ int
    setCharset(mysql);

    // ������ѯ��䣬��ȡ��ʦ�����ڵĿγ̺�
    sprintf(sql,
            "SELECT teaching.cno, course.cname "
            "FROM teaching "
            "JOIN course ON teaching.cno = course.cno "
            "WHERE teaching.tno = %d",
            tno);

    // ִ�в�ѯ
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ��ȡ��ѯ���
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ����Ƿ��н��ڵĿγ�
    if (mysql_num_rows(res) == 0) {
        std::cout << "��û�н����κογ̣��޷�ɾ��ѧ��ѡ����Ϣ��" << std::endl;
        mysql_free_result(res);
        return;
    }

    // �����ʦ�����ڵĿγ̺źͿγ���
    std::cout << "����ڵĿγ����£�" << std::endl;
    while ((row = mysql_fetch_row(res)) != NULL) {
        std::cout << std::left << std::setw(10) << "�γ̺�: " << std::left << std::setw(10) << row[0] << ", �γ���: " << row[1] << std::endl;
    }

    // �ͷŽ����
    mysql_free_result(res);

    int cno;
    std::cout << "������Ҫɾ��ѧ����Ϣ�Ŀγ̺�: ";
    std::cin >> cno;

    // �ٴβ�ѯ��֤����Ŀγ̺��Ƿ��Ǹý�ʦ���ڵĿγ̺�
    sprintf(sql,
            "SELECT * "
            "FROM teaching "
            "WHERE tno = %d AND cno = %d",
            tno, cno);

    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    res = mysql_store_result(&mysql);
    if (res == NULL || mysql_num_rows(res) == 0) {
        std::cout << "����Ŀγ̺Ų�������ڵĿγ̣��޷�ɾ��ѧ��ѡ����Ϣ��" << std::endl;
        mysql_free_result(res);
        return;
    }

    // �ͷŽ����
    mysql_free_result(res);

    int sno;
    std::cout << "������Ҫɾ����ѧ����: ";
    std::cin >> sno;

    // ����ɾ�����
    sprintf(sql, "DELETE FROM sc WHERE sno = %d AND cno = %d", sno, cno);

    // ִ��ɾ������
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    std::cout << "ѧ��ѡ����Ϣɾ���ɹ���" << std::endl;
}

void updateGrade(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[2000];
    int tno = std::stoi(username);  // ���û�������ʦ�ţ�ת��Ϊ int
    setCharset(mysql);

    // ������ѯ��䣬ʹ�ô�������ͼ�򻯲�ѯ
    snprintf(sql, sizeof(sql),
             "SELECT sno, sname, cno, cname, grade FROM View_TeacherCourses WHERE tno = %d",
             tno);

    // ִ�в�ѯ
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ��ȡ��ѯ���
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // �����ʦ�����ڿγ̵�ѧ����Ϣ�ͳɼ�
    std::cout << "����ڵĿγ̵�ѧ����Ϣ���£�" << std::endl;
    int num_fields = mysql_num_fields(res);
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num_fields; ++i) {
        std::cout << std::left << std::setw(15) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // ��ʾ�ָ���
    for (int i = 0; i < num_fields; ++i) {
        std::cout << std::left << std::setw(15) << std::string(15, '-') << "\t";
    }
    std::cout << std::endl;

    // ��ʾ������
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < num_fields; ++i) {
            std::cout << std::left << std::setw(15) << (row[i] ? row[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
    }

    // �ͷŽ����
    mysql_free_result(res);

    // �ռ�Ҫ�޸ĵĳɼ���Ϣ
    int sno, cno;
    std::string grade;
    std::cout << "������Ҫ�޸ĳɼ���ѧ����: ";
    std::cin >> sno;
    std::cout << "�������ѧ���Ŀγ̺�: ";
    std::cin >> cno;
    std::cout << "�������µĳɼ�������Ϊ�գ�: ";
    std::cin >> grade;

    // �����������
    if (grade.empty()) {
        snprintf(sql, sizeof(sql), "UPDATE sc SET grade = NULL WHERE sno = %d AND cno = %d", sno, cno);
    } else {
        snprintf(sql, sizeof(sql), "UPDATE sc SET grade = '%s' WHERE sno = %d AND cno = %d", grade.c_str(), sno, cno);
    }

    // ִ�и��²���
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing update: " << mysql_error(&mysql) << std::endl;
        return;
    }

    std::cout << "ѧ���ɼ����³ɹ���" << std::endl;
}

void setCharset(MYSQL &mysql) {
    if (mysql_set_character_set(&mysql, "gbk")) {
        std::cout << "Error setting character set: " << mysql_error(&mysql) << std::endl;
        exit(1);
    }
}


void addTeacher(MYSQL &mysql)
{

    int flagnum=0;
    int num = 0;
    char sql[2000];
    struct teacher
    {

        int tno, age;
        string tname, sex, degree, password, title, teachYear;
    } teacher_arr[100] = {0};
    goto_error:
    cout<<endl;
    cout << "�������¼���ʦ����:>";
    cin >> num;
    if (num < 1)
    {
        cout << "error input " << endl << "input again:" << endl;
        goto goto_error;
    }

    // char sql[2000];
    // int tno, age;
    // string tname, sex, degree, password,title,teachYear ;

    // cout << "�������ʦ��: ";
    // cin >> tno;
    // cout << "�������ʦ��: ";
    // cin >> tname;
    // cout << "�������Ա�: ";
    // cin >> sex;
    // cout << "����������: ";
    // cin >> age;
    // cout << "������ѧλ: ";
    // cin >> degree;
    // cout << "����������: ";
    // cin >> password;
    // cout<<"������ͷ�Σ� ";
    // cin>>title;
    // cout << "�������ѧ����: ";
    // cin >> teachYear;
    cout<<"����Ľ�ʦ���� 1 ��ͷ";
    cout << "������:  " << endl << "��ʦ�� | " << "��ʦ�� | " << "�Ա� | " << "���� | " << "ѧλ | " << "���� | "
         << "ͷ�� | " << "��ѧ���� | " << endl;

    for (int i = 1; i <= num; i++)
    {

        cin >> teacher_arr[i].tno >> teacher_arr[i].tname >> teacher_arr[i].sex >> teacher_arr[i].age
            >> teacher_arr[i].degree >> teacher_arr[i].password >> teacher_arr[i].title >> teacher_arr[i].teachYear;
        // �����ַ�����
        if(     0 == teacher_arr[i].tno  or  0 == teacher_arr[i].age  or "" == teacher_arr[i].tname or "" == teacher_arr[i].sex
                or "" == teacher_arr[i].degree or "" == teacher_arr[i].title or "" == teacher_arr[i].teachYear or "" == teacher_arr[i].password)
        {
            cout<<"the "<<num<<" line has error"<<num-1<<"lines have been inserted into aams"<<endl;
            break;
        }

        setCharset(mysql);

        // ����������䣬��teacher����ӽ�ʦ��Ϣ
        sprintf(sql,
                "INSERT INTO teacher (tno, tname, sex, age, degree,title,teachYear ) VALUES (%d, '%s', '%s', %d, '%s','%s','%s')",
                teacher_arr[i].tno, teacher_arr[i].tname.c_str(),
                teacher_arr[i].sex.c_str(), teacher_arr[i].age, teacher_arr[i].degree.c_str(),
                teacher_arr[i].title.c_str(), teacher_arr[i].teachYear.c_str());
        if (mysql_query(&mysql, sql)) {
            std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
            cout<<"insert into teacher table error"<<endl;
            continue;
        }

        // ��mysqlϵͳ���ݿ��user����ӵ�¼��Ϣ
        sprintf(sql, "CREATE USER '%d'@'localhost' IDENTIFIED BY '%s'", teacher_arr[i].tno,
                teacher_arr[i].password.c_str());
        if (mysql_query(&mysql, sql)) {
            std::cout << "Error creating user: " << mysql_error(&mysql) << std::endl;
            cout<<"insert into teacher user error"<<endl;
            continue;
        }

        // �����ʦ����aams���ݿ��Ȩ��
        sprintf(sql, "GRANT ALL PRIVILEGES ON aams.* TO '%d'@'localhost'", teacher_arr[i].tno);
        if (mysql_query(&mysql, sql))
        {
            std::cout << "Error granting privileges: " << mysql_error(&mysql) << std::endl;
            cout<<"grant teacher right error"<<endl;
            continue;
        }
        flagnum++;

    }

    cout << num<<"λ��ʦ���� "<<flagnum<<"λ��ʦ��Ϣ��ӳɹ��������¼Ȩ�ޡ�" << endl<<endl<<endl;


    system("pause");
}

void deleteTeacher(MYSQL &mysql) {
    char sql[2000];
    int tno;

    cout << "������Ҫɾ���Ľ�ʦ��: ";
    cin >> tno;

    // �����ַ�����
    setCharset(mysql);

    // ����ɾ����䣬ɾ��teacher���еĽ�ʦ��Ϣ
    sprintf(sql, "DELETE FROM teacher WHERE tno = %d", tno);
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ��mysqlϵͳ���ݿ��user��ɾ����¼��Ϣ
    sprintf(sql, "DROP USER '%d'@'localhost'", tno);
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error dropping user: " << mysql_error(&mysql) << std::endl;
        return;
    }

    cout << "��ʦ��Ϣɾ���ɹ���ɾ����¼Ȩ�ޡ�" << endl;
}

void addStudent(MYSQL &mysql)
{
    char sql[2000];
    char sql2[2000];
    int num;
    int flagnum =0;

    struct student
    {

        int sno, age ,classid;
        string sname, sex, password, mrkyer;
    } studengt_arr[100] = {0};
    goto_error:
    cout<<endl;
    cout << "�������¼��ѧ������:>";
    cin >> num;
    if (num < 1)
    {
        cout << "error input " << endl << "input again:" << endl;
        goto goto_error;
    }

    // int sno, age,classid;
    // string sname, sex,  password,mrkyer;

    // cout << "������ѧ����: ";
    // cin >> sno;
    // cout << "������ѧ����: ";
    // cin >> sname;
    // cout << "�������Ա�: ";
    // cin >> sex;
    // cout << "����������: ";
    // cin>> age;
    // cout << "������ѧ����: ";
    // cin >> mrkyer;
    // cout << "��������: ";
    // cin >> classid;
    // cout << "����������: ";
    // cin >> password;

    cout<<"�����ѧ������ 2 ��ͷ";
    cout << "������:  "<<endl<<"ѧ���� | "<< "���� | "<< "�Ա� | "<< "���� | "<< "��ѧ���� | "<< "��� | "<< "���� | "<<endl;

    for (int i = 1; i <= num; i++)
    {


        cin >> studengt_arr[i].sno>> studengt_arr[i].sname>> studengt_arr[i].sex>> studengt_arr[i].age>>
            studengt_arr[i]. mrkyer>>studengt_arr[i].classid>> studengt_arr[i].password;
        if(     0 == studengt_arr[i].sno  or  0 == studengt_arr[i].age  or  0 == studengt_arr[i].classid or
                "" == studengt_arr[i].sname or "" == studengt_arr[i].sex or "" == studengt_arr[i]. mrkyer or "" == studengt_arr[i].password)
        {
            cout<<"the "<<num<<" line has error"<<num-1<<"lines have been inserted into aams"<<endl;
            break;
        }
        // �����ַ�����
        setCharset(mysql);

        // ����������䣬��stu�����ѧ����Ϣ
        sprintf(sql, "INSERT INTO stu (sno, sname, sex, age, mrkyer,classid) VALUES (%d, '%s', '%s', %d, '%s','%d')",
                studengt_arr[i].sno, studengt_arr[i].sname.c_str(), studengt_arr[i].sex.c_str(), studengt_arr[i].age,
                studengt_arr[i].mrkyer.c_str(),studengt_arr[i].classid);
        if (mysql_query(&mysql, sql))
        {
            std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
            cout<<"insert into stu table error"<<endl;
            continue;
        }

        // ��mysqlϵͳ���ݿ��user����ӵ�¼��Ϣ
        sprintf(sql, "CREATE USER '%d'@'localhost' IDENTIFIED BY '%s'", studengt_arr[i].sno, studengt_arr[i].password.c_str());
        if (mysql_query(&mysql, sql))
        {
            std::cout << "Error creating user: " << mysql_error(&mysql) << std::endl;
            cout<<"insert into student user error"<<endl;
            continue;
        }

        // ����ѧ������aams���ݿ��Ȩ��
        sprintf(sql, "GRANT ALL PRIVILEGES ON aams.* TO '%d'@'localhost'", studengt_arr[i].sno);
        if (mysql_query(&mysql, sql))
        {
            std::cout << "Error granting privileges: " << mysql_error(&mysql) << std::endl;
            cout<<"grant student right error"<<endl;
            continue;
        }

        sprintf(sql2, "GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '%d'@'localhost'", studengt_arr[i].sno);
        if (mysql_query(&mysql, sql2))
        {
            std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
            cout<<"grant student right error on proc1"<<endl;
            continue;
        }
        sprintf(sql2, "GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '%d'@'localhost'",studengt_arr[i].sno);
        if (mysql_query(&mysql, sql2))
        {
            std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
            cout<<"grant student right error on proc2"<<endl;
            continue;
        }
        flagnum++;

    }





    cout <<" ����� "<<num<< "��ѧ����"<<flagnum<<"��ѧ����Ϣ��ӳɹ��������¼Ȩ�ޡ�" << endl<<endl<<endl;

}

void deleteStudent(MYSQL &mysql) {
    char sql[2000];
    char sql2[2000];

    int sno;

    cout << "������Ҫɾ����ѧ����: ";
    cin >> sno;

    // �����ַ�����
    setCharset(mysql);


    // ����ɾ����䣬ɾ��stu���е�ѧ����Ϣ
    sprintf(sql, "DELETE FROM stu WHERE sno = %d", sno);
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ��mysqlϵͳ���ݿ��user��ɾ����¼��Ϣ
    sprintf(sql, "DROP USER '%d'@'localhost'", sno);
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error dropping user: " << mysql_error(&mysql) << std::endl;
        return;
    }

    cout << "ѧ����Ϣɾ���ɹ���ɾ����¼Ȩ�ޡ�" << endl;
}

void assignCourse(MYSQL &mysql) {
    char sql[2000];
    int tno, cno;
    string stime, etime;

    cout << "�������ʦ��: ";
    cin >> tno;
    cout << "������γ̺�: ";
    cin >> cno;
    cout << "������γ̿�ʼʱ��: ";
    cin >> stime;
    cout << "������γ̽���ʱ��: ";
    cin >> etime;

    // �����ַ�����
    setCharset(mysql);

    // ����������䣬��teaching����ӿγ̰�����Ϣ
    sprintf(sql, "INSERT INTO teaching (tno, cno, stime, etime) VALUES (%d, %d, '%s', '%s')", tno, cno, stime.c_str(), etime.c_str());
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    cout << "�γ̰��ųɹ���" << endl;
}
void showSelectedstu(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    setCharset(mysql);
    int tno = std::stoi(username); // ���û�������ʦѧ�ţ�ת��Ϊ int

    // ������ѯ��䣬����stu��course���sc��
    snprintf(sql, sizeof(sql),
             "SELECT sno, sname, cno, cname, grade FROM View_TeacherCourses WHERE tno = %d",
             tno);

    snprintf(sql, sizeof(sql),
             "SELECT sno, sname, cno, cname, grade FROM View_TeacherCourses WHERE tno = %d",
             tno);
    // ִ�в�ѯ
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ��ȡ��ѯ���
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    int num = mysql_num_fields(res);

    // �������
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(15) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // ��ӡ�ָ���
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(15) << std::string(15, '-') << "\t";
    }
    std::cout << std::endl;

    // ��������������е���
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < num; ++i) {
            if (row[i] == NULL) {
                std::cout << std::left << std::setw(15) << "δ����" << "\t";
            } else {
                std::cout << std::left << std::setw(15) << row[i] << "\t";
            }
        }
        std::cout << std::endl;
    }

    // �ͷŽ����
    mysql_free_result(res);
}

void addstu(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[2000];
    int tno = std::stoi(username); // ���û�������ʦ�ţ�ת��Ϊ int
    setCharset(mysql);

    // ������ѯ��䣬��ȡ��ʦ�����ڵĿγ̺�
    /*sprintf(sql,
            "SELECT teaching.cno, course.cname "
            "FROM teaching "
            "JOIN course ON teaching.cno = course.cno "
            "WHERE teaching.tno = %d",
            tno);*/
    snprintf(sql, sizeof(sql),
             "SELECT distinct cno, cname FROM View_TeacherCourses WHERE tno = %d",
             tno);
    // ִ�в�ѯ
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ��ȡ��ѯ���
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // ����Ƿ��н��ڵĿγ�
    if (mysql_num_rows(res) == 0) {
        std::cout << "��û�н����κογ̣��޷����ѧ��ѡ����Ϣ��" << std::endl;
        mysql_free_result(res);
        return;
    }

    // �����ʦ�����ڵĿγ̺źͿγ���
    std::cout << "����ڵĿγ����£�" << std::endl;
    while ((row = mysql_fetch_row(res)) != NULL) {
        std::cout << std::left << std::setw(10) << "�γ̺�: " << std::left << std::setw(10) << row[0] << ", �γ���: " << row[1] << std::endl;
    }

    // �ͷŽ����
    mysql_free_result(res);

    int cno;
    std::cout << "������Ҫ����ѧ����Ϣ�Ŀγ̺�: ";
    std::cin >> cno;

    // �ٴβ�ѯ��֤����Ŀγ̺��Ƿ��Ǹý�ʦ���ڵĿγ̺�
    sprintf(sql,
            "SELECT * "
            "FROM teaching "
            "WHERE tno = %d AND cno = %d",
            tno, cno);

    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    res = mysql_store_result(&mysql);
    if (res == NULL || mysql_num_rows(res) == 0) {
        std::cout << "����Ŀγ̺Ų�������ڵĿγ̣��޷����ѧ��ѡ����Ϣ��" << std::endl;
        mysql_free_result(res);
        return;
    }

    // �ͷŽ����
    mysql_free_result(res);

    int sno;
    std::cout << "������Ҫ�����ѧ����: ";
    std::cin >> sno;

    // �����������
    sprintf(sql, "INSERT INTO sc(sno, cno) VALUES(%d, %d)", sno, cno);

    // ִ�в������
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    std::cout << "ѧ��ѡ����Ϣ��ӳɹ���" << std::endl;
}

void showClassmates(MYSQL &mysql, std::string username) {
    setCharset(mysql);
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"); // ��ֹ������������������

    // ������ѯ���
    std::string query = "SELECT stu.sno, stu.sname, stu.sex, class.classname "
                        "FROM stu "
                        "JOIN class ON stu.classid = class.classid "
                        "WHERE stu.classid = (SELECT classid FROM stu WHERE sno = '" + username + "')";

    // ִ�в�ѯ
    if (mysql_query(&mysql, query.c_str())) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        mysql_close(&mysql);
        return;
    }

    // ��ȡ��ѯ���
    res = mysql_use_result(&mysql);
    int num = mysql_num_fields(res);

    // �õ������е����֣��������
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(15) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // ��������������е���
    while ((row = mysql_fetch_row(res)) != NULL) {
        // ����ǰ���е�ÿһ����Ϣ����
        for (int i = 0; i < num; ++i) {
            std::cout << std::left << std::setw(15) << (row[i] ? row[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
    }

    // �ͷŽ����
    mysql_free_result(res);
}


