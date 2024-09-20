# Leetcode Solutions

This repository contains my solutions to various Leetcode questions. Each file in this repository represents a solution to a specific Leetcode problem.

## Structure

The repository is organized as follows:

- Each solution is stored in a separate file, named according to the question number and title.
- The files are organized in folders based on topics or difficulty levels (optional).
- Along with the code files, there may be accompanying markdown files providing detailed explanations and analysis of the solutions (optional).

## How to Use

You can navigate through the repository to find the solution you are interested in. Each code file contains a solution to a specific Leetcode problem. The file name follows the format `<question_number>_<question_title>.<file_extension>`.

To understand the problem and solution approach, refer to the code comments within the files. Additionally, for a more detailed explanation, you may find accompanying markdown files providing insights and analysis.

## Remove White Space from files
``` bash 
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

std::string replaceSpacesWithUnderscores(const std::string& filename) {
    std::string newFilename = filename;
    for (char& ch : newFilename) {
        if (ch == ' ') {
            ch = '_';
        }
    }
    return newFilename;
}

void renameFilesInDirectory(const fs::path& directoryPath) {
    try {
       
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (entry.is_regular_file()) {
                std::string oldFilename = entry.path().filename().string();
                std::string newFilename = replaceSpacesWithUnderscores(oldFilename);

               
                if (oldFilename != newFilename) {
                    fs::path newPath = entry.path().parent_path() / newFilename;
                    fs::rename(entry.path(), newPath);
                    std::cout << "Renamed: " << oldFilename << " -> " << newFilename << std::endl;
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::string directory;
    
    // Input directory path
    std::cout << "Enter directory path: ";
    std::cin >> directory;

    fs::path directoryPath(directory);

    if (fs::exists(directoryPath) && fs::is_directory(directoryPath)) {
        renameFilesInDirectory(directoryPath);
    } else {
        std::cerr << "Invalid directory!" << std::endl;
    }

    return 0;
}

```


## Contribution

Contributions to this repository are welcome! If you have alternative solutions, optimizations, or new problems to add, feel free to submit a pull request. Please ensure that your code follows the existing naming and formatting conventions.

## Disclaimer

These solutions are solely my own work and are intended for reference purposes. They may not always be the most optimal or efficient solutions. Leetcode questions are frequently updated, so there might be changes or variations to the original problems.

## License

This repository is licensed under the [MIT License](LICENSE).

