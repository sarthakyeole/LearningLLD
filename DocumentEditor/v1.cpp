#include <bits/stdc++.h>
using namespace std;

class DocumentEditor
{
    // chatacteristics
public:
    vector<string> elements;

    // methods
public:
    void addText(string text)
    {
        elements.push_back(text);
    }

    void addImage(string image)
    {
        elements.push_back(image);
    }

    void renderDocument()
    {
        cout << "Document Rendered" << endl;
    }

    void saveDocument()
    {
        cout << "Document Saved" << endl;
    }
};

int main()
{
    DocumentEditor Doc1;

    Doc1.addText("adding to document");
    Doc1.addImage("image.png");
    Doc1.renderDocument();
    Doc1.saveDocument();

    return 0;
}