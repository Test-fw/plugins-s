<?php

/*
    Copyright (C) 2017 Michael Muenz <m.muenz@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
    AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
    OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

function postfix_services()
{
    global $config;

    $services = array();

    if (isset($config['OPNsense']['postfix']['general']['enabled']) && $config['OPNsense']['postfix']['general']['enabled'] == 1) {
        $services[] = array(
            'description' => gettext('Antispam'),
            'configd' => array(
                'restart' => array('postfix restart'),
                'start' => array('postfix start'),
                'stop' => array('postfix stop'),
            ),
            'name' => 'Antispam',
            'pidfile' => '/var/spool/postfix/pid/master.pid'
        );
    }

    return $services;
}

function postfix_syslog()
{
    $syslogconf = array();

    $syslogconf['postfix'] = array('facility' => array('postfix'));

    return $syslogconf;
}

function postfix_xmlrpc_sync()
{
    $result = array();
    $result['id'] = 'postfix';
    $result['section'] = 'OPNsense.postfix';
    $result['description'] = gettext('Antispam');
    return array($result);
}
