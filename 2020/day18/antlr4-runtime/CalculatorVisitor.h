
// Generated from Calculator.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CalculatorParser.
 */
class  CalculatorVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CalculatorParser.
   */
    virtual antlrcpp::Any visitStart(CalculatorParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitExpr(CalculatorParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitOp(CalculatorParser::OpContext *context) = 0;


};

