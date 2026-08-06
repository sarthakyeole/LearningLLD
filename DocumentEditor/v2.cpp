#include <bits/stdc++.h>
using namespace std;

class DocumentElement
{
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return text;
    }
};

class ImageElement : public DocumentElement
{
private:
    string imagePath;

public:
    ImageElement(string imagePath)
    {
        this->imagePath = imagePath;
    }

    string render() override
    {
        return "[image: " + imagePath + "]";
    }
};

class NewLineElement : public DocumentElement 
{
public:
    string render() override 
    {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement 
{
public:
    string render() override 
    {
        return "\t";
    }
};

class Document
{
public:
    vector<DocumentElement *> documentElements;

    void addElement(DocumentElement *element)
    {
        documentElements.push_back(element);
    }

    string render()
    {
        string result;
        for (auto element : documentElements)
        {
            result += element->render();
        }
        return result;
    }
};

class Persistence
{
public:
    virtual void save(string data) = 0;
};

class FileStorage : public Persistence
{
public:
    void save(string data) override
    {
        ofstream outFile("document.txt");
        if(outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to docuemnt.txt" << endl;
        }
        else {
            cout << "Error: Unable to open the file for writing" << endl;
        }
    }
};

class SaveToDatabase : public Persistence
{
public:
    void save(string data) override
    {
        //save to database
    }
}; 

class DocumentEditor
{
public:
    Document* document;
    Persistence* storage;
    string renderedDocument;

public:
    DocumentEditor(Document* document, Persistence* storage) 
    {  
        this->document = document;
        this->storage = storage;
    }

    void addText(string text)
    {
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath)
    {
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine()
    {
        document->addElement(new NewLineElement());
    }

    void addTabSpace()
    {
        document->addElement(new TabSpaceElement());
    }

    string renderDocument()
    {
        if(renderedDocument.empty()) {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDoucument()
    {
        storage->save(renderDocument());
    }
};

int main()
{
    Document* document = new Document();
    Persistence* storage = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document, storage);

    editor->addText("This is new docuemnt");
    editor->addNewLine();
    editor->addImage("picture.png");
    editor->addNewLine();
    editor->addText("I am learning LLD");
    editor->addTabSpace();
    editor->addText("This is document editor following SOLID principles!");

    editor->renderDocument();

    editor->saveDoucument();

    return 0;
}