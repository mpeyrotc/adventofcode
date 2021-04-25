
// Generated from Calculator.g4 by ANTLR 4.9


#include "CalculatorListener.h"

#include "CalculatorParser.h"


using namespace antlrcpp;
using namespace antlr4;

CalculatorParser::CalculatorParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CalculatorParser::~CalculatorParser() {
  delete _interpreter;
}

std::string CalculatorParser::getGrammarFileName() const {
  return "Calculator.g4";
}

const std::vector<std::string>& CalculatorParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CalculatorParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

CalculatorParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CalculatorParser::ExprContext* CalculatorParser::StartContext::expr() {
  return getRuleContext<CalculatorParser::ExprContext>(0);
}


size_t CalculatorParser::StartContext::getRuleIndex() const {
  return CalculatorParser::RuleStart;
}

void CalculatorParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void CalculatorParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

CalculatorParser::StartContext* CalculatorParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CalculatorParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(8);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(6);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

CalculatorParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CalculatorParser::ExprContext *> CalculatorParser::ExprContext::expr() {
  return getRuleContexts<CalculatorParser::ExprContext>();
}

CalculatorParser::ExprContext* CalculatorParser::ExprContext::expr(size_t i) {
  return getRuleContext<CalculatorParser::ExprContext>(i);
}

tree::TerminalNode* CalculatorParser::ExprContext::NUMBER() {
  return getToken(CalculatorParser::NUMBER, 0);
}

CalculatorParser::OpContext* CalculatorParser::ExprContext::op() {
  return getRuleContext<CalculatorParser::OpContext>(0);
}


size_t CalculatorParser::ExprContext::getRuleIndex() const {
  return CalculatorParser::RuleExpr;
}

void CalculatorParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void CalculatorParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


CalculatorParser::ExprContext* CalculatorParser::expr() {
   return expr(0);
}

CalculatorParser::ExprContext* CalculatorParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalculatorParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CalculatorParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, CalculatorParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(16);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      break;
    }

    case 2: {
      setState(11);
      match(CalculatorParser::T__0);
      setState(12);
      expr(0);
      setState(13);
      match(CalculatorParser::T__1);
      break;
    }

    case 3: {
      setState(15);
      match(CalculatorParser::NUMBER);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(24);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(18);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(19);
        op();
        setState(20);
        expr(4); 
      }
      setState(26);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- OpContext ------------------------------------------------------------------

CalculatorParser::OpContext::OpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalculatorParser::OpContext::getRuleIndex() const {
  return CalculatorParser::RuleOp;
}

void CalculatorParser::OpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp(this);
}

void CalculatorParser::OpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalculatorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp(this);
}

CalculatorParser::OpContext* CalculatorParser::op() {
  OpContext *_localctx = _tracker.createInstance<OpContext>(_ctx, getState());
  enterRule(_localctx, 4, CalculatorParser::RuleOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    _la = _input->LA(1);
    if (!(_la == CalculatorParser::T__2

    || _la == CalculatorParser::T__3)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CalculatorParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CalculatorParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CalculatorParser::_decisionToDFA;
atn::PredictionContextCache CalculatorParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CalculatorParser::_atn;
std::vector<uint16_t> CalculatorParser::_serializedATN;

std::vector<std::string> CalculatorParser::_ruleNames = {
  "start", "expr", "op"
};

std::vector<std::string> CalculatorParser::_literalNames = {
  "", "'('", "')'", "'+'", "'*'"
};

std::vector<std::string> CalculatorParser::_symbolicNames = {
  "", "", "", "", "", "NUMBER", "WS"
};

dfa::Vocabulary CalculatorParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CalculatorParser::_tokenNames;

CalculatorParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x8, 0x20, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xb, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x13, 0xa, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x19, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x1c, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x2, 0x3, 0x4, 
    0x5, 0x2, 0x4, 0x6, 0x2, 0x3, 0x3, 0x2, 0x5, 0x6, 0x2, 0x20, 0x2, 0xa, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x12, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xb, 0x5, 0x4, 0x3, 0x2, 0x9, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x8, 0x3, 0x2, 0x2, 0x2, 0xa, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x13, 0x8, 0x3, 0x1, 0x2, 0xd, 0xe, 0x7, 0x3, 
    0x2, 0x2, 0xe, 0xf, 0x5, 0x4, 0x3, 0x2, 0xf, 0x10, 0x7, 0x4, 0x2, 0x2, 
    0x10, 0x13, 0x3, 0x2, 0x2, 0x2, 0x11, 0x13, 0x7, 0x7, 0x2, 0x2, 0x12, 
    0xc, 0x3, 0x2, 0x2, 0x2, 0x12, 0xd, 0x3, 0x2, 0x2, 0x2, 0x12, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x13, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0xc, 
    0x5, 0x2, 0x2, 0x15, 0x16, 0x5, 0x6, 0x4, 0x2, 0x16, 0x17, 0x5, 0x4, 
    0x3, 0x6, 0x17, 0x19, 0x3, 0x2, 0x2, 0x2, 0x18, 0x14, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x9, 0x2, 0x2, 0x2, 0x1e, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x5, 0xa, 0x12, 0x1a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CalculatorParser::Initializer CalculatorParser::_init;
