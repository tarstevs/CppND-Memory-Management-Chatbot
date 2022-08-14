#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id) {
  _id = id;
}

GraphNode::~GraphNode() {
  //// STUDENT CODE
  ////

  // The below line was the bug that occurred when closing the app (aka the "warm up problem").
  // It was a bug because this class doesn't put anything on the heap for _chatBot (i.e. this class isn't
  // responsible for deallocating the heap memory created for _chatBot)
  // delete _chatBot;

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) {
  _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) {
  _chatBot = std::move(chatbot);
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE
  ////

  return (_childEdges[index]).get();

  ////
  //// EOF STUDENT CODE
}