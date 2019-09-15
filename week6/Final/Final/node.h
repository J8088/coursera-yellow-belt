#pragma once

#include "date.h"

#include <string>
#include <memory>

enum Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum LogicalOperation {
	Or,
	And
};

struct Node {
	virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

struct EmptyNode : public Node {
	bool Evaluate(const Date& date, const std::string& event) const override;
};

struct ComparisonNode : public Node {
	ComparisonNode(Comparison cmp);

	const Comparison cmp_;
};

struct DateComparisonNode : public ComparisonNode {
	DateComparisonNode(Comparison cmp, const Date& date);

	bool Evaluate(const Date& date, const std::string& event) const override;

	const Date _date;
};

struct EventComparisonNode : public ComparisonNode {
	EventComparisonNode(Comparison cmp, const std::string& event);

	bool Evaluate(const Date& date, const std::string& event) const override;

	const std::string _event;
};

struct LogicalOperationNode : public Node {
	LogicalOperationNode(LogicalOperation op, std::shared_ptr<Node> left, std::shared_ptr<Node> right);

	bool Evaluate(const Date& date, const std::string& event) const override;

private:
	const LogicalOperation _op;
	std::shared_ptr<const Node> _left, _right;
};
