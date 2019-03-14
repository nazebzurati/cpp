#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>

enum class DocumentFormat {
    MARKDOWN,
    HTML
};

struct ListStrategy {
    virtual void Start(std::ostringstream& stream) {};
    virtual void AddList(std::ostringstream& stream, const std::string& item) = 0;
    virtual void End(std::ostringstream& stream) {};
};

struct MarkdownStrategy: ListStrategy {
    void AddList(std::ostringstream& stream, const std::string& item) override {
        stream << "* " << item << std::endl;
    }
};

struct HtmlStrategy: ListStrategy {
    void Start(std::ostringstream& stream) override {
        stream << "<li>" << std::endl;
    }
    void AddList(std::ostringstream& stream, const std::string& item) override {
        stream << "<li>" << item << "</li>" << std::endl;
    }
    void End(std::ostringstream& stream) override {
        stream << "</ul>" << std::endl;
    }
};

struct ListFormatter {
    
    public:
        void AppendList(const std::vector<std::string>& items) {
            strategy->Start(stream);
            for (auto& item: items) {
                strategy->AddList(stream, item);
            }
            strategy->End(stream);
        }
        void SetOutputFormat(DocumentFormat format) {
            switch (format)
            {
                case DocumentFormat::MARKDOWN:
                    strategy = std::unique_ptr<ListStrategy>(new MarkdownStrategy());
                    break;
                case DocumentFormat::HTML:
                    strategy = std::unique_ptr<ListStrategy>(new HtmlStrategy());
                    break;
                default:
                    break;
            }
        }
        void Clear() { 
            stream.str(""); 
            stream.clear(); 
        }
        std::string Output() const { return stream.str(); }
    
    private:
        std::ostringstream stream;
        std::unique_ptr<ListStrategy> strategy;
};

int main () {
    ListFormatter formatter;

    formatter.SetOutputFormat(DocumentFormat::MARKDOWN);
    formatter.AppendList({"abc", "def", "ghi"});
    std::cout << formatter.Output() << std::endl;
    formatter.Clear();

    formatter.SetOutputFormat(DocumentFormat::HTML);
    formatter.AppendList({"abc", "def", "ghi"});
    std::cout << formatter.Output() << std::endl;
    formatter.Clear();

    return 0;
}