#include "ir_generator.h"
#include "lextual.h"
#include "object_generator.h"
#include "parser.h"

int main() {
    cout << "请输入: " << endl;
    cout << "1. 测试文件路径" << endl;
    cout << "2. 词法分析结果路径" << endl;
    cout << "3. 产生式文件路径" << endl;
    cout << "4. 中间代码路径" << endl;
    cout << "5. 目标代码路径" << endl;
    string right_test, lex_result, productions, ir_result, obj_result;
    right_test=R"(D:\github\Compiling-Principles-Course\resources\right_test.txt)";
    lex_result=R"(D:\github\Compiling-Principles-Course\resources\1.txt)";
    productions=R"(D:\github\Compiling-Principles-Course\resources\productions.txt)";
    ir_result=R"(D:\github\Compiling-Principles-Course\resources\2.txt)";
    obj_result=R"(D:\github\Compiling-Principles-Course\resources\3.txt)";
    Lextual lex;
    lex.getResult(right_test.c_str(), lex_result.c_str());
    Parser pars;
    pars.get_result(productions.c_str(), lex_result.c_str(), ir_result.c_str());
    IRGenerator ir = pars.get_ir();
    ir.divide_block(pars.get_funcstart());
    ObjectGenerator object;


//    map<string, vector<Block> > func = ir.get_func_blocks();
//    vector<Block> v = func["program"];
//    cout << v.size() << endl;
//    for (auto const& i:v) {
//        cout << i.name << endl;
//        for (auto const& f:i.codes) {
//            cout << f.op << ' ' << f.src1 << ' ' << f.src2 << ' ' << f.des << endl;
//        }
//    }
    object.block_addinfo(ir.get_func_blocks());
    object.generate_codes();
    object.output_object_codes(obj_result.c_str());
    return 0;
}