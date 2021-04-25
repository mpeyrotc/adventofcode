//#include <iostream>
//#include <string>
//
//using namespace std;
//
//enum class TOKENS {
//	PLUS, MULT, INTEGER, END, LPAREN, RPAREN
//};
//
//class Lexer
//{
//private:
//	const string m_line;
//	int pos{ 0 };
//
//public:
//	Lexer(string line) :
//		m_line(line)
//	{
//	}
//
//	pair<TOKENS, string> getNextToken()
//	{
//		while (pos < m_line.size())
//		{
//			switch (m_line[pos])
//			{
//			case ' ':
//				++pos;
//				break; // skip
//			case '+':
//				++pos;
//				return make_pair(TOKENS::PLUS, "+");
//			case '*':
//				++pos;
//				return make_pair(TOKENS::MULT, "*");
//			case '(':
//				++pos;
//				return make_pair(TOKENS::LPAREN, "(");
//			case ')':
//				++pos;
//				return make_pair(TOKENS::RPAREN, ")");
//			default:
//				return make_pair(TOKENS::INTEGER, m_line.substr(pos++, 1));
//			}
//		}
//
//		return make_pair(TOKENS::END, "");
//	}
//};
//
//class Parser
//{
//private:
//	Lexer m_lexer;
//	pair<TOKENS, string> m_currentToken;
//
//	unsigned long long result{ 0 };
//
//	void consume(TOKENS expectedToken)
//	{
//		if (m_currentToken.first == expectedToken)
//		{
//			m_currentToken = m_lexer.getNextToken();
//		}
//		else
//		{
//			cout << "Error!" << endl;
//		}
//	}
//
//	unsigned long long term()
//	{
//		auto token = m_currentToken;
//		
//		if (token.first == TOKENS::INTEGER)
//		{
//			consume(TOKENS::INTEGER);
//			return stoull(token.second);
//		}
//		else
//		{
//			consume(TOKENS::LPAREN);
//			unsigned long long result{ expression() };
//			consume(TOKENS::RPAREN);
//
//			return result;
//		}
//	}
//
//	unsigned long long expression()
//	{
//		unsigned long long result{ term() };
//		while (m_currentToken.first == TOKENS::PLUS || m_currentToken.first == TOKENS::MULT)
//		{
//			if (m_currentToken.first == TOKENS::PLUS)
//			{
//				consume(TOKENS::PLUS);
//				result += term();
//			}
//			else if (m_currentToken.first == TOKENS::MULT)
//			{
//				consume(TOKENS::MULT);
//				result *= term();
//			}
//			else
//			{
//				cout << "Error!" << endl;
//			}
//		}
//
//		return result;
//	}
//
//public:
//	Parser(Lexer lexer) :
//		m_lexer(lexer)
//	{
//	}
//
//	unsigned long long parse()
//	{
//		m_currentToken = m_lexer.getNextToken();
//		return expression();
//	}
//};
//
//int main()
//{
//	unsigned long long result{ 0 };
//
//	string line;
//	while (getline(cin, line))
//	{
//		Lexer lexer(line);
//		Parser parser(lexer);
//
//		result += parser.parse();
//	}
//
//	cout << result << endl;
//
//	return 0;
//}