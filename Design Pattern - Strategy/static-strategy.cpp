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

template <typename T>
struct ListFormatter {
    
    public:
        void AppendList(const std::vector<std::string>& items) {
            strategy.Start(stream);
            for (auto& item: items) {
                strategy.AddList(stream, item);
            }
            strategy.End(stream);
        }
        std::string Output() const { return stream.str(); }
    
    private:
        std::ostringstream stream;
        T strategy;
};

int main () {

    ListFormatter<MarkdownStrategy> markdown_formatter;
    markdown_formatter.AppendList({"abc", "def", "ghi"});
    std::cout << markdown_formatter.Output() << std::endl;

    ListFormatter<HtmlStrategy> html_formatter;
    html_formatter.AppendList({"abc", "def", "ghi"});
    std::cout << html_formatter.Output() << std::endl;

    return 0;
}