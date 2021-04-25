
// Generated from Calculator.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CalculatorParser.
 */
class  CalculatorListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(CalculatorParser::StartContext *ctx) = 0;
  virtual void exitStart(CalculatorParser::StartContext *ctx) = 0;

  virtual void enterExpr(CalculatorParser::ExprContext *ctx) = 0;
  virtual void exitExpr(CalculatorParser::ExprContext *ctx) = 0;

  virtual void enterOp(CalculatorParser::OpContext *ctx) = 0;
  virtual void exitOp(CalculatorParser::OpContext *ctx) = 0;


};

