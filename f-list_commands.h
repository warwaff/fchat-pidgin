/*
 * F-List Pidgin - a libpurple protocol plugin for F-Chat
 *
 * Copyright 2011 F-List Pidgin developers.
 *
 * This file is part of F-List Pidgin.
 *
 * F-List Pidgin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * F-List Pidgin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with F-List Pidgin.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef FLIST_COMMANDS_H
#define FLIST_COMMANDS_H

#include "f-list.h"

void flist_update_friend(FListAccount *, const gchar *who, gboolean icon, gboolean adding);

void flist_create_private_channel_action(PurplePluginAction *action);
void flist_set_status_action(PurplePluginAction *action);

int flist_send_message(PurpleConnection *, const gchar *who, const gchar *message, PurpleMessageFlags flags);
int flist_send_channel_message(PurpleConnection *, int id, const char *message, PurpleMessageFlags flags);

void flist_join_channel(PurpleConnection *, GHashTable *components);
void flist_leave_channel(PurpleConnection *, int id);

guint flist_send_typing(PurpleConnection *, const char *, PurpleTypingState);


void flist_get_tooltip(PurpleBuddy *, PurpleNotifyUserInfo *, gboolean full);
gchar *flist_get_status_text(PurpleBuddy *buddy);
void flist_get_profile(PurpleConnection *, const gchar *);

PurpleRoomlist *flist_get_roomlist(PurpleConnection *);
void flist_cancel_roomlist(PurpleRoomlist *);

GList *flist_blist_node_menu(PurpleBlistNode *);

void flist_init_commands();

void flist_process_sending_im(PurpleAccount *account, char *who, char **message, FListAccount *fla);


// Those two fonctions are used by commands whose target window is not sent by the server
// We save the target window when running the command, and hope that the user won't hop
// to another window or run another command before the results get back !
void flist_remember_conversation(FListAccount *fla, PurpleConversation *convo);
PurpleConversation *flist_recall_conversation(FListAccount *fla);
#endif
