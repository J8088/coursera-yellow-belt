#include "node.h"

using namespace std;

bool EmptyNode::Evaluate(const Date& date, const std::string& event) const {
	return true;
}

ComparisonNode::ComparisonNode(Comparison cmp)
	: cmp_(cmp)
{}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& date)
	: ComparisonNode(cmp)
	, _date(date)
{}

bool DateComparisonNode::Evaluate(const Date& other_date, const std::string& other_event) const {
	switch (cmp_) {
	case Comparison::Less:
		return (_date > other_date);
	case Comparison::LessOrEqual:
		return (_date >= other_date);
	case Comparison::Greater:
		return (_date < other_date);
	case Comparison::GreaterOrEqual:
		return (_date <= other_date);
	case Comparison::Equal:
		return (_date == other_date);
	case Comparison::NotEqual:
		return (_date != other_date);
	default:
		throw invalid_argument("Unknown comparison type");
	}
}

EventComparisonNode::EventComparisonNode(Comparison cmp, const std::string& event)
	: ComparisonNode(cmp)
	, _event(event)
{}

bool EventComparisonNode::Evaluate(const Date& other_date, const std::string& other_event) const {
	switch (cmp_) {
	case Comparison::Less:
		return (_event > other_event);
	case Comparison::LessOrEqual:
		return (_event >= other_event);
	case Comparison::Greater:
		return (_event < other_event);
	case Comparison::GreaterOrEqual:
		return (_event <= other_event);
	case Comparison::Equal:
		return (_event == other_event);
	case Comparison::NotEqual:
		return (_event != other_event);
	default:
		throw invalid_argument("Unknown comparison type");
	}
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right)
	: _op(op)
	, _left(left)
	, _right(right)
{}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const {
	switch (_op) {
	case LogicalOperation::Or:
		return _left->Evaluate(date, event) || _right->Evaluate(date, event);
	case LogicalOperation::And:
		return _left->Evaluate(date, event) && _right->Evaluate(date, event);
	default:
		throw invalid_argument("Unknown comparison type");
	}
}
