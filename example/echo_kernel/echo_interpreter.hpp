/***************************************************************************
* Copyright (c) 2016, Johan Mabille and Sylvain Corlay                     *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#ifndef ECHO_INTERPRETER_HPP
#define ECHO_INTERPRETER_HPP

#include "xeus/xinterpreter.hpp"

using xeus::xinterpreter;
using xeus::xjson;
using xeus::xhistory_arguments;

namespace echo_kernel
{
    class echo_interpreter : public xinterpreter
    {

    public:

        echo_interpreter() = default;
        virtual ~echo_interpreter() = default;

    private:

        xjson execute_request_impl(int execution_counter,
                                   const std::string& code,
                                   bool silent,
                                   bool store_history,
                                   const xjson::node_type* user_expressions,
                                   bool allow_stdin) override;

        xjson complete_request_impl(const std::string& code,
                                    int cursor_pos) override;

        xjson inspect_request_impl(const std::string& code,
                                   int cursor_pos,
                                   int detail_level) override;

        xjson history_request_impl(const xhistory_arguments& args) override;

        xjson is_complete_request_impl(const std::string& code) override;

        xjson comm_info_request_impl(const std::string& target_name) override;

        xjson kernel_info_request_impl() override;

        void input_reply_impl(const std::string& value) override;
    };
}

#endif
