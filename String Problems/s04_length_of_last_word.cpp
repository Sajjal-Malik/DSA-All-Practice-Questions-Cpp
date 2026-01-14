#include <bits/stdc++.h>
using namespace std;

/**
 * Calculates the length of the last word in a string by manually
 * traversing from the end of the string backwards.
 */
int getLengthOfLastWordManual(std::string input_text)
{
    int currentIndex = input_text.length() - 1;
    int wordLength = 0;

    // Phase 1: Skip any trailing whitespace at the end of the string
    while (currentIndex >= 0 && input_text[currentIndex] == ' ')
    {
        currentIndex--;
    }

    // Phase 2: Count characters until the next space or start of string is reached
    while (currentIndex >= 0 && input_text[currentIndex] != ' ')
    {
        wordLength++;
        currentIndex--;
    }

    return wordLength;
}

/**
 * Calculates the length of the last word using C++ Standard Library
 * string manipulation functions for cleaner, more expressive code.
 */
int getLengthOfLastWordSTL(std::string input_text)
{
    // Trim trailing whitespace by finding the last non-space character
    size_t lastCharPos = input_text.find_last_not_of(' ');

    // Handle edge case: string is empty or contains only spaces
    if (lastCharPos == std::string::npos)
        return 0;

    // Create a temporary string containing only the content up to the last word
    std::string trimmedText = input_text.substr(0, lastCharPos + 1);

    // Find the position of the space immediately preceding the last word
    size_t lastSpacePos = trimmedText.find_last_of(' ');

    // If no space exists, the entire string is one word; otherwise, extract the suffix
    if (lastSpacePos == std::string::npos)
    {
        return trimmedText.length();
    }

    return trimmedText.substr(lastSpacePos + 1).length();
}

int main()
{
    std::string phrase1 = "luffy is still joyboy";
    std::string phrase2 = "   fly me   to   the moon  ";

    // Example Output
    std::cout << "Phrase 1 Last Word Length: " << getLengthOfLastWordManual(phrase1) << std::endl;
    std::cout << "Phrase 2 Last Word Length: " << getLengthOfLastWordSTL(phrase2) << std::endl;

    return 0;
}
