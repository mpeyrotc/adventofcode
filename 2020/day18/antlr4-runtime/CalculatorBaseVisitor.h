
// Generated from Calculator.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorVisitor.h"


/**
 * This class provides an empty implementation of CalculatorVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CalculatorBaseVisitor : public CalculatorVisitor {
public:

  virtual antlrcpp::Any visitStart(CalculatorParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(CalculatorParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp(CalculatorParser::OpContext *ctx) override {
    return visitChildren(ctx);
  }


};

