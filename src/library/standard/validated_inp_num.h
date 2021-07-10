#include "__init__.h"

#ifndef VALIDATED_INP_NUM_H
#define VALIDATED_INP_NUM_H

/*____for name, sex, ...____*/
bool is_alpha(char target) {
    return (
        ('a' <= target && target <= 'z') ||
        ('A' <= target && target <= 'Z') ||
        (target == ' ') ||
        (target == '.') ||
        (target == '-')
    );
}

bool no_duplicate_space(char target, char* array) {
    int len = strlen(array);
    if (len == 1 || len == 0) return true;
    return !(array[len - 1] == target && target == ' ');
}

/*____for number____*/
bool is_number(char target) {
    return isdigit(target);
}

bool rule_one_chain_default(char target, char* chain) {
    return true;
}

std::string getLimitInput(
        bool (*rule_one_char)(char), // {function} check the input char is valid
        bool (*rule_one_chain)(char, char*) // {function} check the char array is valid
    ) {
	char* tmp_result = (char*) malloc(sizeof(char)*MAXCHARS);
	int index = 0;
	int ch;	

	while ((ch = getch()) != EOF && ch != ENTER) {
		if (isdigit((char)ch)) {
			tmp_result[index++] = ch;
			printf ("%c", ch);
		} else if(ch == BACKSPACE && index > 0) {
			tmp_result[--index] = 0;
			printf("%c %c", BACKSPACE, BACKSPACE);
		}
	}

    memset(tmp_result + index, 0, index * 2);
    std::string result(tmp_result);
	free(tmp_result);

	return result;
}

void Nhap_so(int &n, int x, int y) { // x, y la toa do con tro quay ve de nhap lai sau khi thong bao
    string user_string_num = "";

    int is_num = 0;
    int decimal_count = 0; // Kiem tra xem so duoc nhap co phai la so thap phan khong
    int user_converted_num;

    bool is_num_bool = false;     // Kiem tra xem co phai la so nguyen khong (Dung de thoat khoi vong lap)
    bool contains_spaces = false; // Kiem tra xem so duoc nhap co chua khoang trang khong. VD: 4   4
    bool retype = false;          // Muc dich la de khi nhap du lieu khong hop le no hien len thong bao yeu cau nhap lai

    do
    {
        if (retype == true)
        {
            ShowCur(1);
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);
        }
        do {
            // getline(cin, user_string_num);
	    user_string_num = getOnlyNumber();
            if (user_string_num == "") // Kiem tra truong hop bo trong du lieu
            {
                thong_bao("Khong duoc bo trong du lieu.");
                ShowCur(1);
                xoa_man_hinh(x, y, 70, 1);
                gotoxy(x, y);
            }
        } while (user_string_num == "");
        for (int i = 0; i < user_string_num.size(); i++)
        {
            if (isspace(user_string_num[i]) == true)
            {
                contains_spaces = true;
            }
        }
        if (user_string_num[0] == '-')
        {
            is_num = 0;
        }
        if (user_string_num[0] == '0' && isdigit(user_string_num[1]))
        { // Neu user nhap so co so 0 o dau => So khong hop le
            is_num = 0;
        }
        else
        {
            for (int i = 0; i < user_string_num.size(); i++)
            {
                // Kiem tra tung ki tu xem co phai la so khong
                if (isdigit(user_string_num[i]))
                {
                    is_num++;
                }
                // Kiem tra xem co phai so thap phan khong (Do ta can int nen neu nhap float <=> Khong hop le)
                if (user_string_num[i] == '.')
                {
                    decimal_count++;
                }
            }
        }
        if (decimal_count == 1)
        {
            is_num = 0;
        }
        // Neu input dung la 1 so nguyen hop le
        if (is_num == user_string_num.size() && contains_spaces == false)
        {
            // Convert user_string_num tu string sang int bang phuong thuc str_stream_object
            stringstream str_stream_object(user_string_num);
            // Khi nay str_stream_object da chua noi dung cua user_string_num, ta can phai dua no vao user_converted_num
            str_stream_object >> user_converted_num;
            is_num_bool = true; // Dung de ra khoi vong lap
        }
        else
        {
            // Thong bao loi
            thong_bao("So khong hop le.");
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);

            // Reset lai cac gia tri
            is_num_bool = false;
            is_num = 0;
            decimal_count = 0;
            contains_spaces = false;
            retype = true;
        }
    } while (is_num_bool == false);
    n = user_converted_num;
}
void Nhap_so_chinh_sua(int &n, int x, int y)
{ // x, y la toa do con tro quay ve de nhap lai sau khi thong bao
    string user_string_num = "";

    int is_num = 0;
    int decimal_count = 0; // Kiem tra xem so duoc nhap co phai la so thap phan khong
    int user_converted_num;

    bool is_num_bool = false;     // Kiem tra xem co phai la so nguyen khong (Dung de thoat khoi vong lap)
    bool contains_spaces = false; // Kiem tra xem so duoc nhap co chua khoang trang khong. VD: 4   4
    bool retype = false;          // Muc dich la de khi nhap du lieu khong hop le no hien len thong bao yeu cau nhap lai

    do
    {
        if (retype == true)
        {
            ShowCur(1);
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);
        }
	user_string_num = getOnlyNumber();
        for (int i = 0; i < user_string_num.size(); i++)
        {
            if (isspace(user_string_num[i]) == true)
            {
                contains_spaces = true;
            }
        }
        if (user_string_num[0] == '-') // Kiem tra xem co phai so am khong
        {
            is_num = 0;
        }
        if (user_string_num[0] == '0' && isdigit(user_string_num[1])) // Neu user nhap so co so 0 o dau => So khong hop le
        {
            is_num = 0;
        }
        else
        {
            for (int i = 0; i < user_string_num.size(); i++)
            {
                // Kiem tra tung ki tu xem co phai la so khong
                if (isdigit(user_string_num[i]))
                {
                    is_num++;
                }
                // Kiem tra xem co phai so thap phan khong (Do ta can int nen neu nhap float <=> Khong hop le)
                if (user_string_num[i] == '.')
                {
                    decimal_count++;
                }
            }
        }
        if (decimal_count == 1)
        {
            is_num = 0;
        }
        // Neu input dung la 1 so nguyen hop le
        if (is_num == user_string_num.size() && contains_spaces == false)
        {
            // Convert user_string_num tu string sang int bang phuong thuc str_stream_object
            stringstream str_stream_object(user_string_num);
            // Khi nay str_stream_object da chua noi dung cua user_string_num, ta can phai dua no vao user_converted_num
            str_stream_object >> user_converted_num;
            is_num_bool = true; // Dung de ra khoi vong lap
        }
        else
        {
            // Thong bao loi
            thong_bao("So khong hop le.");
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);
            // Reset lai cac gia tri
            is_num_bool = false;
            is_num = 0;
            decimal_count = 0;
            contains_spaces = false;
            retype = true;
        }
    } while (is_num_bool == false);
    n = user_converted_num;
}
void Nhap_ngay(int &n, int x, int y)
{ // x, y la toa do con tro quay ve de nhap lai sau khi thong bao
    string user_string_num = "";

    int is_num = 0;
    int decimal_count = 0; // Kiem tra xem so duoc nhap co phai la so thap phan khong
    int user_converted_num;

    bool is_num_bool = false;     // Kiem tra xem co phai la so nguyen khong (Dung de thoat khoi vong lap)
    bool contains_spaces = false; // Kiem tra xem so duoc nhap co chua khoang trang khong. VD: 4   4
    bool retype = false;          // Muc dich la de khi nhap du lieu khong hop le no hien len thong bao yeu cau nhap lai

    do
    {
        if (retype == true)
        {
            ShowCur(1);
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);
        }
        do {
            // getline(cin, user_string_num);
	    user_string_num = getOnlyNumber();
            if (user_string_num == "") // Kiem tra truong hop bo trong du lieu
            {
                thong_bao("Khong duoc bo trong du lieu.");
                ShowCur(1);
                xoa_man_hinh(x, y, 70, 1);
                gotoxy(x, y);
            }
        } while (user_string_num == "");
        for (int i = 0; i < user_string_num.size(); i++)
        {
            if (isspace(user_string_num[i]) == true)
            {
                contains_spaces = true;
            }
        }
        if (user_string_num[0] == '-') // Kiem tra xem co phai so am khong
        {
            is_num = 0;
        }
        if (user_string_num[0] == '0' && isdigit(user_string_num[1])) // Neu user nhap so co so 0 o dau => So khong hop le
        {
            is_num = 0;
        }
        else
        {
            for (int i = 0; i < user_string_num.size(); i++)
            {
                // Kiem tra tung ki tu xem co phai la so khong
                if (isdigit(user_string_num[i]))
                {
                    is_num++;
                }
                // Kiem tra xem co phai so thap phan khong (Do ta can int nen neu nhap float <=> Khong hop le)
                if (user_string_num[i] == '.')
                {
                    decimal_count++;
                }
            }
        }
        if (decimal_count == 1)
        {
            is_num = 0;
        }
        // Neu input dung la 1 so nguyen hop le
        if (is_num == user_string_num.size() && contains_spaces == false)
        {
            // Convert user_string_num tu string sang int bang phuong thuc str_stream_object
            stringstream str_stream_object(user_string_num);
            // Khi nay str_stream_object da chua noi dung cua user_string_num, ta can phai dua no vao user_converted_num
            str_stream_object >> user_converted_num;
            is_num_bool = true; // Dung de ra khoi vong lap
        }
        else
        {
            // Thong bao loi
            thong_bao("Ngay khong hop le. Xin nhap lai");
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);
            // Reset lai cac gia tri
            is_num_bool = false;
            is_num = 0;
            decimal_count = 0;
            contains_spaces = false;
            retype = true;
        }
    } while (is_num_bool == false);
    n = user_converted_num;
}
void Nhap_thang(int &n, int x, int y)
{ // x, y la toa do con tro quay ve de nhap lai sau khi thong bao
    string user_string_num = "";

    int is_num = 0;
    int decimal_count = 0; // Kiem tra xem so duoc nhap co phai la so thap phan khong
    int user_converted_num;

    bool is_num_bool = false;     // Kiem tra xem co phai la so nguyen khong (Dung de thoat khoi vong lap)
    bool contains_spaces = false; // Kiem tra xem so duoc nhap co chua khoang trang khong. VD: 4   4
    bool retype = false;          // Muc dich la de khi nhap du lieu khong hop le no hien len thong bao yeu cau nhap lai

    do
    {
        if (retype == true)
        {
            ShowCur(1);
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);
        }
        do {
            // getline(cin, user_string_num);
	    user_string_num = getOnlyNumber();
            if (user_string_num == "") // Kiem tra truong hop bo trong du lieu
            {
                thong_bao("Khong duoc bo trong du lieu.");
                ShowCur(1);
                xoa_man_hinh(x, y, 70, 1);
                gotoxy(x, y);
            }
        } while (user_string_num == "");
        for (int i = 0; i < user_string_num.size(); i++)
        {
            if (isspace(user_string_num[i]) == true)
            {
                contains_spaces = true;
            }
        }
        if (user_string_num[0] == '-') // Kiem tra xem co phai so am khong
        {
            is_num = 0;
        }
        if (user_string_num[0] == '0' && isdigit(user_string_num[1])) // Neu user nhap so co so 0 o dau => So khong hop le
        {
            is_num = 0;
        }
        else
        {
            for (int i = 0; i < user_string_num.size(); i++)
            {
                // Kiem tra tung ki tu xem co phai la so khong
                if (isdigit(user_string_num[i]))
                {
                    is_num++;
                }
                // Kiem tra xem co phai so thap phan khong (Do ta can int nen neu nhap float <=> Khong hop le)
                if (user_string_num[i] == '.')
                {
                    decimal_count++;
                }
            }
        }
        if (decimal_count == 1)
        {
            is_num = 0;
        }
        // Neu input dung la 1 so nguyen hop le
        if (is_num == user_string_num.size() && contains_spaces == false)
        {
            // Convert user_string_num tu string sang int bang phuong thuc str_stream_object
            stringstream str_stream_object(user_string_num);
            // Khi nay str_stream_object da chua noi dung cua user_string_num, ta can phai dua no vao user_converted_num
            str_stream_object >> user_converted_num;
            is_num_bool = true; // Dung de ra khoi vong lap
        }
        else
        {
            // Thong bao loi
            thong_bao("Thang khong hop le. Xin nhap lai");
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);
            // Reset lai cac gia tri
            is_num_bool = false;
            is_num = 0;
            decimal_count = 0;
            contains_spaces = false;
            retype = true;
        }
    } while (is_num_bool == false);
    n = user_converted_num;
}
void Nhap_nam(int &n, int x, int y)
{ // x, y la toa do con tro quay ve de nhap lai sau khi thong bao
    string user_string_num = "";

    int is_num = 0;
    int decimal_count = 0; // Kiem tra xem so duoc nhap co phai la so thap phan khong
    int user_converted_num;

    bool is_num_bool = false;     // Kiem tra xem co phai la so nguyen khong (Dung de thoat khoi vong lap)
    bool contains_spaces = false; // Kiem tra xem so duoc nhap co chua khoang trang khong. VD: 4   4
    bool retype = false;          // Muc dich la de khi nhap du lieu khong hop le no hien len thong bao yeu cau nhap lai

    do
    {
        if (retype == true)
        {
            ShowCur(1);
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);
        }
        do {
            // getline(cin, user_string_num);
	    user_string_num = getOnlyNumber();
            if (user_string_num == "") // Kiem tra truong hop bo trong du lieu
            {
                thong_bao("Khong duoc bo trong du lieu.");
                ShowCur(1);
                xoa_man_hinh(x, y, 70, 1);
                gotoxy(x, y);
            }
        } while (user_string_num == "");
        for (int i = 0; i < user_string_num.size(); i++)
        {
            if (isspace(user_string_num[i]) == true)
            {
                contains_spaces = true;
            }
        }
        if (user_string_num[0] == '-') // Kiem tra xem co phai so am khong
        {
            is_num = 0;
        }
        if (user_string_num[0] == '0' && isdigit(user_string_num[1])) // Neu user nhap so co so 0 o dau => So khong hop le
        {
            is_num = 0;
        }
        else
        {
            for (int i = 0; i < user_string_num.size(); i++)
            {
                // Kiem tra tung ki tu xem co phai la so khong
                if (isdigit(user_string_num[i]))
                {
                    is_num++;
                }
                // Kiem tra xem co phai so thap phan khong (Do ta can int nen neu nhap float <=> Khong hop le)
                if (user_string_num[i] == '.')
                {
                    decimal_count++;
                }
            }
        }
        if (decimal_count == 1)
        {
            is_num = 0;
        }
        // Neu input dung la 1 so nguyen hop le
        if (is_num == user_string_num.size() && contains_spaces == false)
        {
            // Convert user_string_num tu string sang int bang phuong thuc str_stream_object
            stringstream str_stream_object(user_string_num);
            // Khi nay str_stream_object da chua noi dung cua user_string_num, ta can phai dua no vao user_converted_num
            str_stream_object >> user_converted_num;
            is_num_bool = true; // Dung de ra khoi vong lap
        }
        else
        {
            // Thong bao loi
            thong_bao("Nam khong hop le. Xin nhap lai");
            xoa_man_hinh(x, y, 70, 1);
            gotoxy(x, y);
            // Reset lai cac gia tri
            is_num_bool = false;
            is_num = 0;
            decimal_count = 0;
            contains_spaces = false;
            retype = true;
        }
    } while (is_num_bool == false);
    n = user_converted_num;
}
#endif /*VALIDATED_INP_NUM_H*/
