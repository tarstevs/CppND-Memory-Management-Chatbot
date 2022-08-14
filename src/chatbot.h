#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot {
 private:
  // data handles (owned)
  wxBitmap *_image; // avatar image

  // data handles (not owned)
  GraphNode *_currentNode;
  GraphNode *_rootNode;
  ChatLogic *_chatLogic;

  // proprietary functions
  int ComputeLevenshteinDistance(std::string s1, std::string s2);

 public:
  // constructors / destructors
  ChatBot();                     // constructor WITHOUT memory allocation
  explicit ChatBot(std::string filename); // constructor WITH memory allocation

  /**
   * Rule of 5
   */
  // 1. Copy constructor
  ChatBot(const ChatBot &rhs);
  // 2. Move constructor
  ChatBot(ChatBot &&rhs) noexcept;
  // 3. Copy assignment
  ChatBot &operator=(const ChatBot &rhs);
  // 4. Move assignment
  ChatBot &operator=(ChatBot &&rhs) noexcept;
  // 5. Destructor
  ~ChatBot();


  //// STUDENT CODE
  ////

  ////
  //// EOF STUDENT CODE

  // getters / setters
  void SetCurrentNode(GraphNode *node);
  void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
  void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
  ChatLogic *GetChatLogicHandle() { return _chatLogic; }
  wxBitmap *GetImageHandle() { return _image; }

  // communication
  void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
