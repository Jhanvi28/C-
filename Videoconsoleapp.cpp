#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Video
{

private:
    int video_no;
    string video_title;
    string video_type;

public:
    Video(int no, string title, string type)
    {
        video_no = no;
        video_title = title;
        video_type = type;
    }

    void display()
    {
        cout << "No : " << video_no << " Title : " << video_title << " Type : " << video_type << endl;
    }
};

vector<Video> video_list;

void addVideo()
{

    int no;
    string title, type;

    cout << "Enter video no : " << endl;
    cin >> no;
    cin.ignore();
    cout << "Enter video title : " << endl;
    getline(cin, title);
    cout << "Enter video type : " << endl;
    getline(cin, type);
    video_list.push_back(Video(no, title, type));
    cout << "Video added successfully" << endl;
}

void listVideo()
{
    if (video_list.empty())
    {

        cout << "No video available" << endl;
    }
    else
    {
        for (Video video : video_list)
        {
            video.display();
        }
    }
}

void deleteVideo()
{
    if (video_list.empty())
    {
        cout << "No video avaliable" << endl;
    }
    else
    {
        int index;
        cout << "Enter video index you want to delete : " << endl;
        cin >> index;
        if(index >= 1 && video_list.size())
        {
            video_list.erase(video_list.begin() + index - 1);
            cout << "Video deleted successfully at index : " << index << endl;
        }
        else
        {
            cout << "Invalid index";
        }
    }
    
    cout << "Delete";
}

int main()
{

    int choise;

    do
    {
        cout << "----- Menu -----" << endl;
        cout << "Enter 1 for add video " << endl;
        cout << "Enter 2 for list all video " << endl;
        cout << "Enter 3 for delte video " << endl;
        cout << "Enter 4 for exit " << endl;
        cout << "Enter your choise : " << endl;
        cin >> choise;
        cin.ignore();
        switch (choise)
        {
        case 1:
            addVideo();
            break;

        case 2:
            listVideo();
            break;

        case 3:
            deleteVideo();
            break;

        case 4:
            cout << "----- Exit ----- " << endl;
            break;

        default:
            cout << "Invalid choise";
            break;
        }
    } while (choise != 4);

    return 0;
}
