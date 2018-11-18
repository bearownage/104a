void emit (astree* tree) {
   switch (tree->symbol) {
      case TOK_ROOT  :  break;
      case TOK_PARAM :  break;
      case TOK_WHILE  : break;
      case TOK_RETURN :  break;
      case TOK_FIELD :   break; // Update field attribute
      case TOK_VARDECL : break;
      case TOK_INT :  break;
      case TOK_IDENT: break;
      case TOK_IF :  break;
      case TOK_ELSE :  break;
      case TOK_STRING :  break;
      case TOK_CALL :  break;
      case TOK_NOT  :  break; 
      case TOK_STRUCT : break;
      case ';'   :  break;
      case '='   :                break;
      case '+'   :  break;
      case '-'   :  break;
      case '*'   :  break;
      case '/'   :  break;
      case '%'   :  break;
      case TOK_POS   :  break;
      case TOK_NEG   :  break;
      case TOK_DECLID :        break;
      case TOK_INTCON :        break;
      case TOK_STRINGCON :  break;
      default    : assert (false);                    break;
   }
}
